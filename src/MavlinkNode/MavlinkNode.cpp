#include "Common.h"
#include "MavlinkNode.h"
#ifndef _WIN32
#include <pthread.h>
#endif

MavlinkNode::MavlinkNode(string myIP)
	: _socket(myIP, MAVLINK_RX_PORT)
{
	_first = true;
	_doubleCnt=0;

	_running = true;

#ifdef _WIN32
	_thread = CreateThread(NULL,NULL,RxThread,this,NULL,NULL);
#else
	pthread_create(&_thread, NULL, RxThread, this);
#endif

	_packet.data = new unsigned char[MAX_UDP_PACKET_SIZE];
}

MavlinkNode::~MavlinkNode()
{
	_running = false;
#ifdef _WIN32
	if(WaitForSingleObject(_thread,100)!=WAIT_OBJECT_0)
	{
		TerminateThread(_thread,10);
	}
#else
	_socket.shutdown();
#ifdef __APPLE__
	pthread_cancel(_thread);
#endif
	pthread_join(_thread, NULL);
#endif
	delete [] _packet.data;
}

#ifdef _WIN32
DWORD WINAPI MavlinkNode::RxThread(LPVOID param)
#else
void* MavlinkNode::RxThread(void* param)
#endif
{
	int numRead;
	string srcAddr;
	unsigned short srcPort;

	MavlinkNode* p = (MavlinkNode*)param;
  while (p->_running)
  {
    try
    {
      numRead = p->_socket.recvFrom(p->_packet.data, MAX_UDP_PACKET_SIZE, srcAddr, srcPort);
    }
    catch (...)
    {
      continue;
    }
		
		if(numRead<0)
		{
			