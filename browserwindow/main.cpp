/*
    Copyright (c) 2009-10 Qtrac Ltd. All rights reserved.

    This program or module is free software: you can redistribute it
    and/or modify it under the terms of the GNU General Public License
    as published by the Free Software Foundation, either version 3 of
    the License, or (at your option) any later version. It is provided
    for educational purposes and is distributed in the hope that it will
    be useful, but WITHOUT ANY WARRANTY; without even the implied
    warranty of MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE. See
    the GNU General Public License for more details.
*/

#include "browserwindow.hpp"
#include "option_parser.hpp"
#include <QApplication>
#include <QDialog>
#include <QDialogButtonBox>
#include <QNetworkProxy>
#include <QPushButton>
#include <QVBoxLayout>
#include <QWebSettings>


int enableNetworkProxying()
{
    AQP::OptionParser parser(qApp->arguments(), qApp->translate(
            "main",
            "usage: {program} [options]\n\n"
            "To use a proxy server set the host and port,\n"
            "and if required the username, password, and proxy "
            "type.\n\nVersion 1.0.0 Copyright (c) 2010 Qtrac Ltd. "
            "All rights reserved.\n"));
    AQP::StringOptionPtr typeOpt = parser.addStringOption(
            "t", "type");
    typeOpt->setHelp(qApp->translate("main", "proxy type"));
    typeOpt->setDefaultValue("socks5");
    typeOpt->setAcceptableValues(QStringList() << "socks5" << "http");
    AQP::StringOptionPtr hostOpt = parser.addStringOption(
            "H", "host");
    hostOpt->setHelp(qApp->translate("main",
            "hostname, e.g., www.example.com"));
    AQP::IntegerOptionPtr portOpt = parser.addIntegerOption(
            "p", "port");
    portOpt->setHelp(qApp->translate("main",
            "port number, e.g., 1080"));
    AQP::StringOptionPtr userOpt = parser.addStringOption(
            "u", "username");
    userOpt->setHelp(qApp->translate("main", "username"));
    AQP::StringOptionPtr passwordOpt = parser.addStringOption(
            "P", "password");
    passwordOpt->setHelp(qApp->translate("main", "password"));
    if (!parser.parse())
        return 2;

    if (parser.hasValue("host")) {
        QNetworkProxy proxy;
        proxy.setType(parser.string("type") == "socks5"
                ? QNetworkProxy::Socks5Proxy
                : QNetworkProxy::HttpProxy);
        proxy.setHostName(parser.string("host"));
        if (parser.hasValue("port"))
            proxy.setPort(parser.integer("port"));
        if (parser.hasValue("username"))
            proxy.setUser(parser.string("username"));
        if (parser.hasValue("password"))
            proxy.setPassword(parser.string("password"));
        QNetworkProxy::setApplicationProxy(proxy);
    }
    return 0;
}


int main(int argc, char *argv[])
{
    QApplication app(argc, argv);
    app.setApplicationName(app.translate("main", "Browser Window"));
#ifdef Q_WS_MAC
    app.setCursorFlashTime(0);
#endif

    if (int error = enableNetworkProxying())
        return error;

    QWebSettings *webSettings = QWebSettings::globalSettings();
    webSettings->setAttribute(QWebSettings::AutoLoadImages, true);
    webSettings->setAttribute(QWebSettings::JavascriptEnabled, true);
    webSettings->setAttribute(QWebSettings::PluginsEnabled, true);
#if QT_VERSION >= 0x040500
    webSettings->setAttribute(QWebSettings::ZoomTextOnly, true);
#endif
#ifdef DEBUG
    webSettings->setAttribute(QWebSettings::DeveloperExtrasEnabled,
                              true);
#endif

    QString url("en.wikipedia.org/wiki/Main_Page");
    if (argc > 1)
        url = argv[1];
    QDialog dialog;
    BrowserWindow *browser = new BrowserWindow(url);
    if (argc > 2) browser->showToolBar(false); // For testing; don't quote
    QDialogButtonBox *buttonBox = new QDialogButtonBox;
    QPushButton *quitButton = buttonBox->addButton(
            app.translate("main", "&Quit"),
            QDialogButtonBox::AcceptRole);
    QVBoxLayout *layout = new QVBoxLayout;
    layout->addWidget(browser, 1);
    layout->addWidget(buttonBox);
    dialog.setLayout(layout);
    QObject::connect(quitButton, SIGNAL(clicked()),
                     &dialog, SLOT(accept()));
    dialog.setWindowTitle(app.applicationName());
    dialog.setWindowFlags(Qt::WindowSystemMenuHint);
    dialog.show();
    return app.exec();
}
