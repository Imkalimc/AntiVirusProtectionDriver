#pragma once

#include <ntifs.h>
#include <ntddk.h>

#define DEVICE_NAME         L"\\Device\AVDriver"
#define SYMBOLIC_LINK_NAME  L"\\DosDevices\\AVDriver"  //�������豸��

#define IOCTL_PROTECTION_PROCESS  CTL_CODE(FILE_DEVICE_UNKNOWN, 0x800, METHOD_BUFFERED, FILE_ANY_ACCESS)  //���̱�������pid���ɣ�Win10,11�������
#define IOCTL_PROTECTION_PROCESS8 CTL_CODE(FILE_DEVICE_UNKNOWN, 0x801, METHOD_BUFFERED, FILE_ANY_ACCESS)  //���̱�������pid���ɣ�Win8�������
#define IOCTL_TERMINATE_PROCESS   CTL_CODE(FILE_DEVICE_UNKNOWN, 0x802, METHOD_BUFFERED, FILE_ANY_ACCESS)  //ǿɱ����
#define IOCTL_HIDDEN_PROCESS      CTL_CODE(FILE_DEVICE_UNKNOWN, 0x803, METHOD_BUFFERED, FILE_ANY_ACCESS)  //���ؽ���(ûɶ��qwq)win10.11�����
#define IOCTL_HIDDEN_PROCESS8     CTL_CODE(FILE_DEVICE_UNKNOWN, 0x804, METHOD_BUFFERED, FILE_ANY_ACCESS)  //���ؽ���(ûɶ��qwq)win8�����

PDEVICE_OBJECT g_DeviceObject = NULL;
NTSTATUS CreateDevice(PDRIVER_OBJECT DriverObject);
NTSTATUS DeleteDevice();
VOID DriverUnload(_In_ PDRIVER_OBJECT DriverObject);
NTSTATUS DispatchCreateClose(_In_ PDEVICE_OBJECT DeviceObject, _Inout_ PIRP Irp);
NTSTATUS DispatchDeviceControl(_In_ PDEVICE_OBJECT DeviceObject, _Inout_ PIRP Irp);

