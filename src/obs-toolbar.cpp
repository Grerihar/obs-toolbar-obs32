#include <obs-module.h>
#include <obs-frontend-api.h>
#include <QWidget>
#include <QPushButton>
#include <QVBoxLayout>
#include <QLabel>

OBS_DECLARE_MODULE()
OBS_MODULE_USE_DEFAULT_LOCALE("obs-toolbar", "en-US")

MODULE_EXPORT const char *obs_module_description(void)
{
    return "OBS Toolbar (Updated for OBS 32)";
}

void create_toolbar_dock()
{
    QWidget *dock_widget = new QWidget();
    dock_widget->setWindowTitle("OBS Toolbar");

    QVBoxLayout *layout = new QVBoxLayout(dock_widget);

    QPushButton *btn_start_stream = new QPushButton("Start Streaming");
    QObject::connect(btn_start_stream, &QPushButton::clicked, [](){
        obs_frontend_streaming_start();
    });

    QPushButton *btn_stop_stream = new QPushButton("Stop Streaming");
    QObject::connect(btn_stop_stream, &QPushButton::clicked, [](){
        obs_frontend_streaming_stop();
    });

    QPushButton *btn_start_record = new QPushButton("Start Recording");
    QObject::connect(btn_start_record, &QPushButton::clicked, [](){
        obs_frontend_recording_start();
    });

    QPushButton *btn_stop_record = new QPushButton("Stop Recording");
    QObject::connect(btn_stop_record, &QPushButton::clicked, [](){
        obs_frontend_recording_stop();
    });

    layout->addWidget(new QLabel("OBS Toolbar"));
    layout->addWidget(btn_start_stream);
    layout->addWidget(btn_stop_stream);
    layout->addWidget(btn_start_record);
    layout->addWidget(btn_stop_record);

    dock_widget->setLayout(layout);

    obs_frontend_add_dock(dock_widget);
}

bool obs_module_load(void)
{
    blog(LOG_INFO, "[obs-toolbar] plugin loaded successfully");
    create_toolbar_dock();
    return true;
}
