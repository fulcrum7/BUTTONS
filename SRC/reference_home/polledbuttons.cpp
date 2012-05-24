#include "polledbuttons.h"
#include <QHBoxLayout>
#include <QLayout>
#include <unistd.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <fcntl.h>

AlarmButtons::AlarmButtons(QWidget *qw) : QWidget(qw)
{
	// prepare layout
	QHBoxLayout *layout = new QHBoxLayout;

	// prepare buttons	

	pb[0] = new QPushButton("LOCK");
	layout->addWidget(pb[0]);
	pb[1] = new QPushButton("HOME");
	layout->addWidget(pb[1]);
	

	// add layout

	setLayout(layout);

	// title 

	setWindowTitle("Home");

	// FIXME: prepare two pollings threads with pointers

	thread = new PollingAlarmButtonsThread(pb);	

}


AlarmButtons::~AlarmButtons()
{
	

	delete thread;

}



PollingAlarmButtonsThread::PollingAlarmButtonsThread(QPushButton **buttons)
{

	pb = buttons;
	fd = open("/dev/fma1125dc_home",O_RDONLY);
	qDebug("File is %d",fd);
	start(); 

}

PollingAlarmButtonsThread::~PollingAlarmButtonsThread()
{
	terminate();
	close(fd);


}

void PollingAlarmButtonsThread::run()
{
	char status_reg = 0;

	while(1)
	{
		qDebug("In loop");
		read(fd,&status_reg,1);
		qDebug("The bitfield is here %0X\n",status_reg);

		(pb)[0]->setDown((status_reg & 0x10));
		(pb)[1]->setDown((status_reg & 0x01));			

		

	}	

}


