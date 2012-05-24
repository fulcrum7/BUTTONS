#ifndef POLLEDBUTTONS_H
#define POLLEDBUTTONS_H

#include <QtGui>
#include <QWidget>
#include <QPushButton>
#include <QThread>
#include <QFile>



class PollingAlarmButtonsThread;

class AlarmButtons : public QWidget
{
	private:
	QPushButton *pb[8];
	PollingAlarmButtonsThread *thread;
	public:
	
	AlarmButtons(QWidget *);
	virtual ~AlarmButtons();

};


class PollingAlarmButtonsThread : public QThread
{
	
	private:
	QPushButton **pb;
	QFile *file;	
	int fd;
	public:
	PollingAlarmButtonsThread(QPushButton **);
	~PollingAlarmButtonsThread();
	protected:
	void run();
};



#endif
