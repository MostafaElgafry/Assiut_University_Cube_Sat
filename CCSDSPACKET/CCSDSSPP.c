#include "CCSDSSPP.h"
#include "string.h"
#include "stdlib.h"


unsigned char CCSDSPacketProtocolHeadrGN (unsigned char PVN,PacketType pt,SecHeader SH,unsigned short APPID,segmentation Seg,
                                        unsigned short Packet_Sequence_Count_or_Name,unsigned short Packet_Data_Length,Primarry_Hrader * ph)
										{
											if (ph != NULL)
											{
												ph->Primary_Header_Fields.Packet_Version_Number=PacketVersionNumber;
												ph->Primary_Header_Fields.Packet_Type=Telcommand_pcket;
												ph->Primary_Header_Fields.Sec_Header_Flag=Without_Sec_header;
												ph->Primary_Header_Fields.APPID=Idle_packet_APPID;
												ph->Primary_Header_Fields.SEQUENCE_FLAGS=continue_segment;
												ph->Primary_Header_Fields.PacketSeqCount=Packet_Sequence_Count_or_Name;
												ph->Primary_Header_Fields.PD_Length=Packet_Data_Length;

											}
											else
											{

											return -1;

											}
											ph = (Primarry_Hrader*) malloc(5);
										}

int  CCSDSPacketConstruction (Primarry_Hrader * ph,unsigned char *Data,int Data_Length,unsigned char * Data_output)
										{

										if (ph != NULL)
											{
												ph->Primary_Header_Fields.PD_Length=Data_Length;

											}
											else
											{

											return -1;

											}

										Data_output = realloc(Data_output,sizeof(5+Data_Length));
										memcpy(Data_output,ph,5);
										memcpy(Data_output+5,Data,Data_Length);
										}
										
unsigned char * CCSDSPacketProtocolInit(unsigned char PVN,PacketType pt,SecHeader SH,unsigned int APPID,segmentation Seg,
                                        unsigned short Packet_Sequence_Count_or_Name,unsigned short Packet_Data_Length,Primarry_Hrader * ph)
										{













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