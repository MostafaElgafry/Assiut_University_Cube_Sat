#include "CCSDSSPP.h"
#include "string.h"
#include "stdlib.h"


unsigned char CCSDSPacketProtocolHeadrGN (unsigned char PVN,PacketType pt,SecHeader SH,unsigned short APPID,segmentation Seg,
                                        unsigned short Packet_Sequence_Count_or_Name,unsigned short Packet_Data_Length,Primarry_Hrader * ph)
										{
											if (ph != NULL)
											{
												ph->Primary_Header_Fields.Packet_Version_Number=PVN;
												ph->Primary_Header_Fields.Packet_Type=pt;
												ph->Primary_Header_Fields.Sec_Header_Flag=SH;
												ph->Primary_Header_Fields.APPID=APPID;
												ph->Primary_Header_Fields.SEQUENCE_FLAGS=Seg;
												ph->Primary_Header_Fields.PacketSeqCount=Packet_Sequence_Count_or_Name;
												ph->Primary_Header_Fields.PD_Length=Packet_Data_Length;

											}
											else
											{

											return -1;

											}
											ph = (Primarry_Hrader*) malloc(5);
										}

unsigned char  CCSDSPacketConstruction (Primarry_Hrader * ph,unsigned char *Data,int Data_Length,unsigned char * Data_output)
										{

										if (ph != NULL)
											{
												ph->Primary_Header_Fields.PD_Length=Data_Length;
												Data_output = realloc(Data_output,sizeof(5+Data_Length));
												memcpy(Data_output,ph,5);
												memcpy(Data_output+5,Data,Data_Length);
											}
											else
											{

											return -1;

											}

										
										}
										

void CCSDSPacketSetSequenceNumber (unsigned short Packet_Sequence_Count_or_Name,Primarry_Hrader * ph)
										{
										
										ph->Primary_Header_Fields.PacketSeqCount=Packet_Sequence_Count_or_Name;
										
										}
void CCSDSPacketSetSequenceSegmentationHeader (segmentation Seg,Primarry_Hrader * ph)
										{
										
										ph->Primary_Header_Fields.SEQUENCE_FLAGS=Seg;	
										
										}
void CCSDSPacketSetVersionNumber (unsigned char PVN,Primarry_Hrader * ph)
										{
										
										ph->Primary_Header_Fields.Packet_Version_Number=PVN;
										
										}
void CCSDSPacketSetPacketType (PacketType pt,Primarry_Hrader * ph)
										{
											
										ph->Primary_Header_Fields.Packet_Type=pt;	
										
										}
void CCSDSPacketSetSecHeaderFlage (SecHeader SH,Primarry_Hrader * ph)
										{
											
										ph->Primary_Header_Fields.Sec_Header_Flag=SH;	
										
										}
void CCSDSPacketSetAPPID (unsigned short APPID,Primarry_Hrader * ph)
										{
											
										ph->Primary_Header_Fields.APPID=APPID;
										
										}
void CCSDSPacketSetLength (unsigned short Packet_Data_Length,Primarry_Hrader * ph)
										{
											
										ph->Primary_Header_Fields.PD_Length=Packet_Data_Length;	
										
										}
int  CCSDSPacketExtraction (Primarry_Hrader * ph,unsigned char *Data,int Data_Length,unsigned char * DataField)
										{
											
										}
unsigned char * CCSDSPacketProtocolInit(unsigned char PVN,PacketType pt,SecHeader SH,unsigned int APPID,segmentation Seg,
                                        unsigned short Packet_Sequence_Count_or_Name,unsigned short Packet_Data_Length,Primarry_Hrader * ph)
										{













										}										