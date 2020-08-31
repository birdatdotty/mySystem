Данный набор программ является демонстрацией моей идеи для администрирования linux сиситемами (все элементы являются простой демонстрацией, без работы над дизайном)

systemd - демон работает из под root и используется только выполнения конкретных команд, требующие повышенных прав. Доступен по dbus
untitled16 - графическая оболочка для выполнения команд из под обычного пользователя
wsUntitled17 - ws сервер для доступа из web приложений (index.html - приметивное приложения для передачи комманд )

собирать 3 программы по шаблону:

 cd systemd; mkdir build; cd $_; cmake ..; make; cd ../..

 cd untitled16; mkdir build; cd $_; cmake ..; make; cd ../..
 
 cd wsUntitled17; mkdir build; cd $_; cmake ..; make; cd ../..

systemd и untitled17 - работают как сервисы, работающие через dbus и для их работы надо:

	systemd:	cp dbus-test.conf /etc/dbus-1/system.d/dbus-test.conf
	
			cp test.service /etc/systemd/system/
			
	wsUntitled17:	cp dbus-wstest.conf /etc/dbus-1/system.d/
	
поправить test.service ("ExecStart=.../test" - на "ExecStart=/путь/к/test")

для проверки:

	systemctl start test.service # запуск сервиса для выполнения из под root
	
	.../untitled16 # для запуска qt(qwidget) программы, которая общается с сервисом по dbus
	
	.../wsUntitled17 # запускает ws на 9999 порту и явлеется proxy для web приложения (с test.service общается по dbus)
	

Хочу еще раз повторится: проект больше демонстрация подхода, чем готовое приложение
