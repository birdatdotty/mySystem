// https://habr.com/ru/post/165959/
#include <QCoreApplication>
#include <QDebug>
#include <QDBusConnection>
#include "TestController.h"

#define SERVICE_NAME "test.service"
#define OBJECT_PATH "/test"

int main(int argc, char *argv[]) {
	QCoreApplication app(argc, argv);
	// Создаём соединение с системной шиной D-Bus
	QDBusConnection conn = QDBusConnection::systemBus();

	// Регистрируем сервис
	if (! conn.registerService(SERVICE_NAME)) {
		qDebug() << "Error:" <<  conn.lastError().message();
		exit(EXIT_FAILURE);
	}

	TestController controller;
	// Регистрируем контроллер
	conn.registerObject(OBJECT_PATH, &controller, QDBusConnection::ExportAllContents);

	return app.exec();
}
