#pragma once

#include <curl\curl.h>
#include <iostream>
#include <fstream>
#include <sstream>
#include <string>
#include <vector>


namespace mr {
	//helping functions for read and write
	size_t read_request_data(char *ptr, size_t size, size_t nmemb, void *userdata);
	size_t write_response_data(char *ptr, size_t size, size_t nmemb, void *userdata);

	//recognize function send request and get response
	std::string recognize(const std::string path);

	//parse response
	std::vector<std::string> parseRequest(std::string request);
}