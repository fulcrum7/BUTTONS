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
	for(int i = 0; i < 8; i++)
	{
		pb[i] = new QPushButton(tr("Button %1").arg(i));
		layout->addWidget(pb[i]);

	}

	// add layout

	setLayout(layout);

	// title 

	setWindowTitle("Alarm");

	// FIXME: prepare two pollings threads with pointers

	thread = new PollingAlarmButtonsThread(pb);	

}


AlarmButtons::~AlarmButtons()
{
	
	//thread->exit();
	delete thread;

}



PollingAlarmButtonsThread::PollingAlarmButtonsThread(QPushButton **buttons)
{

	pb = buttons;
	fd = open("/dev/fma1125dc_alarm",O_RDONLY);
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
		qDebug("The bitfield is %0x\n",status_reg);
		for(int i = 0; i < 8; i++)
		{
			(pb)[i]->setDown((status_reg&0x01));
			
			status_reg >>= 1; 
		}

	}	

}


