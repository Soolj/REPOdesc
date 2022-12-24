#pragma once

#include "PracticalSocket.h"
#include "Utility/FastDelegate.h"
#include "UDPPacket.h"

#ifdef __APPLE__
#pragma clang diagnostic push
#pragma clang diagnostic ignored "-Waddress-of-packed-member"
#endif
#include "mavlink/common/mavlink.h"
#ifdef __APPLE__
#pragma clang diagnostic pop
#endif

#include <vector>
using namespace fastdelegate;
using std::vector;

#define MAVLINK_TX_PORT 14555
#define MAVLINK_RX_PORT 14550 

typedef FastDelegate2<mavlink_message_t, const UDPPacket&> MavlinkNodeCallback;

class MavlinkNode
{
public:
	MavlinkNode(string myIP="127.0.0.1");
	~MavlinkNode();

#ifdef _WIN32
	static DWORD WINAPI RxThread(LPVOID param);
#else
	static void* RxThread(void* param);
#endif

	void SetCallback(MavlinkNodeCallback callback, void* arg)
  {
		this->callback = callback;
		this->callbackArg = arg;
	}	

	v