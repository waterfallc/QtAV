#include <QtAV/AVThread.h>
#include <private/AVThread_p.h>

namespace QtAV {
AVThread::AVThread(QObject *parent) :
	QThread(parent),d_ptr(new AVThreadPrivate())
{
}

AVThread::AVThread(AVThreadPrivate &d, QObject *parent)
    :QThread(parent),d_ptr(&d)
{
}

AVThread::~AVThread()
{
}

void AVThread::stop()
{
    d_ptr->stop = true;
    wakeAll();
    //terminate();
}

void AVThread::wakeAll()
{
    d_ptr->condition.wakeAll();
}

void AVThread::setClock(AVClock *clock)
{
    d_ptr->clock = clock;
}

AVClock* AVThread::clock() const
{
    return d_ptr->clock;
}

QAVPacketQueue* AVThread::packetQueue() const
{
    return &d_ptr->packets;
}

void AVThread::setDecoder(AVDecoder *decoder)
{
    d_ptr->dec = decoder;
}

AVDecoder* AVThread::decoder() const
{
    return d_ptr->dec;
}

void AVThread::setOutput(AVOutput *out)
{
    d_ptr->writer = out;
}

AVOutput* AVThread::output() const
{
    return d_ptr->writer;
}

}

