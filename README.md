# VoiceCommand
Voice capture and recognize with Yandex Speech API. (типа крутой текст на английском)

Проект проработает, вероятно, до 20.12.2016, потом кончится тестовый ключ для speech api яндекса.

[Презентация к проекту](https://docs.google.com/presentation/d/1_r90u9xb-2RRAz_ThnQ7ma4gGIWe_fK-7Ttf7eRG7bo/edit?usp=sharing)

## Инструкция по запуску всего этого на VisualStudio 2015
1. Качаем c [официального сайта](https://curl.haxx.se/download.html) curl архив с исходниками.
2. Компилируем
 * Открываем командную строку разработчика
 * cd [путь до папки с исходниками]\winbuild
 *     nmake /f Makefile.vc mode=dll
 * Ждём
3. Закидываем в include directory [путь до папки с исходниками curl]\builds\libcurl-vc-x86-release-dll-ipv6-sspi-winssl\include.
4. Закидываем в library path [путь до папки с исходниками curl]\builds\libcurl-vc-x86-release-dll-ipv6-sspi-winssl\lib.
5. В зависимости добавляем libcurl.lib.
6. Ну и собственно qt должен быть как бы.
7. Собирем проект, в появившуюся папку можно закинуть файл data.ini
 можно не закидывать там пробная пользовательская информация.
8. И также закидываем libcurl.dll из папки [путь до папки с исходниками curl]\builds\libcurl-vc-x86-release-dll-ipv6-sspi-winssl\bin.
9. Шлём мне вк скрины ошибок и я помогаю собрать.
10. Так же есть архив с бинарниками и необходимыми *.dll.

## Бинари под win
Так же можете скачать архив с исполняемым файлом и необходимыми dll по [ссылке](https://drive.google.com/file/d/0B2d73FNuqKBecnV5UVVrZW5EYmc/view?usp=sharing)

## Интерфейс:
* Go - при нажатии и удерживании записывает голос, при отпускании передаёт на сервер яндекса,
распознаёт и заускает назначенное пользователем действие.
* Пункт Add actions в меню - там вы можете задать действие(*.exe файл или любой другой, 
открывается тем что установлено по дефолту в системе) и соответствующую команду, пример задания смотреть в файле data.ini.
* Ну и какие то другие элементы, думаю ревьюверы догадаются мне написать.


## ToDo:
Много чего не сделано, может доработаю:
- [x] Сохранение в файл настроек пользователя (ну тут изи)
- [ ] Потоковая отправка звука на сервера яндекса (сложность проекта меняется с 2/5 на 4/5 ибо потратил 30 рабочих часов на попытки сделать потоково)
- [x] Глобальные хоткеи (неохото лезть в winapi было, а qt даёт только хоткеи при фокусе)
- [ ] Отказ от записи звука через qt (здесь тоже убил нормально так времени, openal не расковырял а directshow не понравился поэтому пока так)
- [ ] Красивый интерфейс
- [x] Добавить opensavedialog на указатели директорий
- [ ] Добавить дополнительные настройки запуска процесса
- [x] Нужно делать детач для запускаемого процесса, иначе вместе с программой закрывается вызванное
приложение
- [ ] Так же после окончания подписки яндекса, было бы интересно переделать приложение под движок pocketsphinx -
оффлайн распознавание голоса, из заданного словаря
