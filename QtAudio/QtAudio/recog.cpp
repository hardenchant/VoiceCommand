#include <recog.h>


size_t mr::read_request_data(char *ptr, size_t size, size_t nmemb, void *userdata)
{
	std::ifstream* f = (std::ifstream*)userdata;
	size_t n = size * nmemb;  
	f->read(ptr, n);
	size_t result = f->gcount();  
	return result;
}
size_t mr::write_response_data(char *ptr, size_t size, size_t nmemb, void *userdata)
{
	std::stringstream* s = (std::stringstream*)userdata;
	size_t n = size * nmemb;  
	s->write(ptr, n);
	return n;
}
std::string mr::recognize(const std::string path) {
	auto curl = curl_easy_init();
	if (curl)
	{
		curl_easy_setopt(curl, CURLOPT_HEADER, 1);
		curl_easy_setopt(curl, CURLOPT_POST, 1);
		curl_easy_setopt(curl, CURLOPT_VERBOSE, 1);
		curl_easy_setopt(curl, CURLOPT_IPRESOLVE, CURL_IPRESOLVE_V4);

		struct curl_slist *headers = NULL;

		headers = curl_slist_append(headers, "Content-Type: audio/x-wav");
		curl_easy_setopt(curl, CURLOPT_HTTPHEADER, headers);
		//set info
		curl_easy_setopt(curl, CURLOPT_USERAGENT, "Windows 10/2016");
		//set api key, language and query format
		curl_easy_setopt(curl, CURLOPT_URL, 
			"asr.yandex.net/asr_xml?key=2afd54fe-46b0-4a8c-bc51-3225594f96a2&uuid=01ae13cb7d496daa1e644628b58fb536&topic=queries&lang=ru-RU");
		
		std::ifstream fileStream(path, std::ifstream::binary);
		if (!fileStream) {
			return "\n\n";
		}
		fileStream.seekg(0, fileStream.end);
		int length = fileStream.tellg();
		fileStream.seekg(0, fileStream.beg);

		curl_easy_setopt(curl, CURLOPT_READFUNCTION, &mr::read_request_data);
		curl_easy_setopt(curl, CURLOPT_POSTFIELDSIZE, length);
		curl_easy_setopt(curl, CURLOPT_READDATA, &fileStream);

		std::stringstream buffer;

		curl_easy_setopt(curl, CURLOPT_WRITEFUNCTION, &mr::write_response_data);
		curl_easy_setopt(curl, CURLOPT_WRITEDATA, &buffer);

		CURLcode code = curl_easy_perform(curl); //где ты юзаешь code?
		
		curl_free(headers);
		curl_easy_cleanup(curl);
		
		return buffer.str();
	}
	return "\n\n";
}
std::vector<std::string> mr::parseRequest(std::string response) {
	std::vector<std::string> parseVariants;
	if (response == "\n\n") {
		parseVariants.push_back("CurlErr");
		return parseVariants;
	}

	auto pos_b = response.find("<var");
	auto pos_e = response.find("</rec");

	while (pos_b!=std::string::npos) {
		pos_b = response.find(">", pos_b);
		pos_e = response.find("</var", pos_b);
		std::string variant(response, ++pos_b, pos_e - pos_b);
		parseVariants.push_back(variant);
		pos_b = response.find("<var", pos_e);
	}

	return parseVariants;
}
