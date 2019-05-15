// SHIFT + ALT + F identar
// https://aticleworld.com/function-pointer-in-c/

typedef void (*pfSend)(const char *pcData, const int ciLen);

typedef int (*pfRead)(char *pData);

struct SERVER_COM
{
    int iLenData;
    pfSend pSendToServer;
    pfRead pReadFromServer;

} GATEWAYCOM;

typedef struct
{

    int (*OpenSocket)(void);

    int (*CloseSocket)(int);

    int (*ReadFromServer)(int, char *, short);

    int (*WriteToServer)(int, char *, short);

} sCommStructure;

sCommStructure *CreateTcpComm(void)
{

    sCommStructure *psComTcpIp = malloc(sizeof(sCommStructure));

    if (psComTcpIp != NULL)
    {

        psComTcpIp->OpenSocket = &TcpSocketCreate;
        psComTcpIp->CloseSocket = &TcpSocketClose;
        psComTcpIp->ReadFromServer = &TcpSocketReceive;
        psComTcpIp->WriteToServer = &TcpSocketSend;
    }

    return psComTcpIp;
}

sCommStructure *CreateUdpComm(void)
{

    sCommStructure *psComUdp = malloc(sizeof(sCommStructure));

    if (psComUdp != NULL)
    {

        psComUdp->OpenSocket = &UdpSocketCreate;
        psComUdp->CloseSocket = &UdpSocketClose;
        psComUdp->ReadFromServer = &UdpSocketReceive;
        psComUdp->WriteToServer = &UdpSocketSend;
    }
    return psComUdp;
}

int CommunicationWithTcp(char *Rqst, short lenRqst, char *Rsp, short RvcSize)
{

    int hSocket = -1;
    short shortRetval = -1;

    //Call Create TcpComm function for tcp/Ip communication
    sCommStructure *psTcpcomm = CreateTcpComm();

    //Create Socket

    hSocket = psTcpcomm->OpenSocket();
    if (hSocket < 0)
    {
        printf("Socket Creation Failed: SOCKET_HANDLER = %d", hSocket);
        return SOCKET_FAILED;
    }
    else
    {
        printf("Socket Creation Success: SOCKET_HANDLER = %d", hSocket);
    }

    //Send data
    shortRetval = psTcpcomm->WriteToServer(hSocket, Rqst, lenRqst);
    if (shortRetval < 0)
    {
        printf("Socket Request Send Failed: RET_VALUE = %d", shortRetval);

        return SEND_FAILED;
    }
    else
    {
        printf("Socket Request Send Success: RET_VALUE = %d", shortRetval);
    }

    shortRetval = psTcpcomm->ReadFromServer(hSocket, Rsp, RvcSize);

    if (shortRetval < 0)
    {
        printf("Socket REsponse Receive Failed: RET_VALUE = %d", shortRetval);

        return RECV_FAILED;
    }
    else
    {
        printf("Socket Request Receive Success: RET_VALUE = %d", shortRetval);
    }

    psTcpcomm->CloseSocket(hSocket);

    return 0;
}

WDF_PNPPOWER_EVENT_CALLBACKS pnpPowerCallbacks;

WDF_PNPPOWER_EVENT_CALLBACKS_INIT(&pnpPowerCallbacks);
pnpPowerCallbacks.EvtDevicePrepareHardware = MyDeviceEvtDevicePrepareHardware;
pnpPowerCallbacks.EvtDeviceD0Entry = MyDeviceEvtDeviceD0Entry;
pnpPowerCallbacks.EvtDeviceD0Exit = MyDeviceEvtDeviceD0Exit;

WdfDeviceInitSetPnpPowerEventCallbacks(DeviceInit, &pnpPowerCallbacks);

int main()
{

    return 0;
}