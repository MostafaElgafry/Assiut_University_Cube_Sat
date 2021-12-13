#ifndef CCSDSSPP_H_INCLUDED
#define CCSDSSPP_H_INCLUDED
#define Littel_Endian 0
#define Big_Endian 1
#define MMCSTelemetryAppid   0b10101010101
#define MMCSTelecommandAppid 1365
#define PacketVersionNumber 0b000
#define Telcommand_pcket_Type 0b1
#define Telemmetry_pcket_Type 0b0

#define Idle_packet_APPID 0b11111111111
unsigned short Packet_Sequence_Count_or_Name;// Packet Sequence Count or Packet Name
unsigned short Packet_Data_Length;
typedef enum segmentation
{
  continue_segment=0, //‘00’ if the Space Packet contains a continuation segment of User Data;
  first_segmen=1,
  last_segment=2,
  unsegmented=3

}segmentation;

typedef enum PacketType
{
  Telemmetry_pcket=0,
  Telcommand_pcket=1
}PacketType;

typedef enum SecHeader
{
Without_Sec_header= 0b0,
With_Sec_header = 0b1
}SecHeader;

typedef union Primarry_Hrader
{
    unsigned char Primarry_Hrader_[6];
       struct
        {
            unsigned     char a0                   ;
            unsigned     char a1                    ;
            unsigned     char a2                   ;
            unsigned     char a3                    ;
            unsigned     char a4                   ;
            unsigned     char a5                 ;
        }ShiftRegBytes;

       /* unsigned char Packet_Version_Number_;//:3;
        unsigned char Packet_Type_;//:1;
        unsigned char Sec_Header_Flag_;//;//:1;
        unsigned char  APPID_;//:11;// APPLICATION PROCESS IDENTIFIER
        unsigned char SEQUENCE_FLAGS:2;
        unsigned char PSeqCount_;//:14;  //PACKET SEQUENCE COUNT OR PACKET NAME
        unsigned char PD_Length_;//:16;  //PACKET DATA LENGTH*/
struct
{
        unsigned int b0:1;
        unsigned int b1:1;
        unsigned int b2:1;
        unsigned int b3:1;
        unsigned int b4:1;
        unsigned int b5:1;
        unsigned int b6:1;
        unsigned int b7:1;
        unsigned int b8:1;
        unsigned int b9:1;
        unsigned int b10:1;
        unsigned int b11:1;
        unsigned int b12:1;
        unsigned int b13:1;
        unsigned int b14:1;
        unsigned int b15:1;
        unsigned int b16:1;
        unsigned int b17:1;
        unsigned int b18:1;
        unsigned int b19:1;
        unsigned int b20:1;
        unsigned int b21:1;
        unsigned int b22:1;
        unsigned int b23:1;
        unsigned int b24:1;
        unsigned int b25:1;
        unsigned int b26:1;
        unsigned int b27:1;
        unsigned int b28:1;
        unsigned int b29:1;
        unsigned int b30:1;
        unsigned int b31:1;
        unsigned int b32:1;
        unsigned int b33:1;
        unsigned int b34:1;
        unsigned int b35:1;
        unsigned int b36:1;
        unsigned int b37:1;
        unsigned int b38:1;
        unsigned int b39:1;
        unsigned int b40:1;
        unsigned int b41:1;
        unsigned int b42:1;
        unsigned int b43:1;
        unsigned int b44:1;
        unsigned int b45:1;
        unsigned int b46:1;
        unsigned int b47:1;


}ShiftRegBits;
struct Primary_Header_Fields
{


        unsigned short Packet_Version_Number:3;
        unsigned short Packet_Type:1;
        unsigned short Sec_Header_Flag:1;
        unsigned short  APPID:11;// APPLICATION PROCESS IDENTIFIER
        unsigned short SEQUENCE_FLAGS:2;
        unsigned short PSeqCount:14;  //PACKET SEQUENCE COUNT OR PACKET NAME
        unsigned short PD_Length:16;  //PACKET DATA LENGTH

    }Primary_Header_Fields;
}Primarry_Hrader;
typedef union
{
  struct
{
        unsigned int b0:1;
        unsigned int b1:1;
        unsigned int b2:1;
        unsigned int b3:1;
        unsigned int b4:1;
        unsigned int b5:1;
        unsigned int b6:1;
        unsigned int b7:1;
        unsigned int b8:1;
        unsigned int b9:1;
        unsigned int b10:1;
        unsigned int b11:1;
        unsigned int b12:1;
        unsigned int b13:1;
        unsigned int b14:1;
        unsigned int b15:1;
        unsigned int b16:1;
        unsigned int b17:1;
        unsigned int b18:1;
        unsigned int b19:1;
        unsigned int b20:1;
        unsigned int b21:1;
        unsigned int b22:1;
        unsigned int b23:1;
        unsigned int b24:1;
        unsigned int b25:1;
        unsigned int b26:1;
        unsigned int b27:1;
        unsigned int b28:1;
        unsigned int b29:1;
        unsigned int b30:1;
        unsigned int b31:1;
        unsigned int b32:1;
        unsigned int b33:1;
        unsigned int b34:1;
        unsigned int b35:1;
        unsigned int b36:1;
        unsigned int b37:1;
        unsigned int b38:1;
        unsigned int b39:1;
        unsigned int b40:1;
        unsigned int b41:1;
        unsigned int b42:1;
        unsigned int b43:1;
        unsigned int b44:1;
        unsigned int b45:1;
        unsigned int b46:1;
        unsigned int b47:1;


}RegBits;
}REGBITS;
typedef union
{
 unsigned char Primarry_Hrader_[6];
}CCSDSPacketHeader;
typedef union
{

    unsigned char Appid[2];
    unsigned short appid;
}APPID;
int CheckEndianness();
unsigned char * CCSDSPacketProtocolInit(unsigned char PVN,PacketType pt,SecHeader SH,unsigned int APPID,segmentation Seg,
                                        unsigned short Packet_Sequence_Count_or_Name,unsigned short Packet_Data_Length,Primarry_Hrader * ph);

void CCSDSPacketProtocolHeadrGN (unsigned char PVN,PacketType pt,SecHeader SH,unsigned short APPID,segmentation Seg,
                                        unsigned short Packet_Sequence_Count_or_Name,unsigned short Packet_Data_Length,Primarry_Hrader * ph);

void CCSDSPacketSetSequenceNumber (unsigned short Packet_Sequence_Count_or_Name,Primarry_Hrader * ph);

void CCSDSPacketSetSequenceSegmentationHeader (segmentation Seg,Primarry_Hrader * ph);
void CCSDSPacketSetVersionNumber (unsigned char PVN,Primarry_Hrader * ph);
void CCSDSPacketSetPacketType (PacketType pt,Primarry_Hrader * ph);
void CCSDSPacketSetSecHeaderFlage (SecHeader SH,Primarry_Hrader * ph);
void CCSDSPacketSetAPPID (unsigned short APPID,Primarry_Hrader * ph);
void CCSDSPacketSetLength (unsigned short Packet_Data_Length,Primarry_Hrader * ph);
int CCSDSPacketConstruction (Primarry_Hrader * ph,unsigned char *Data,int Data_Length,unsigned char * Data_output);
int CCSDSPacketExtraction (Primarry_Hrader * ph,unsigned char *Data,int Data_Length,unsigned char * DataField);


#endif // CCSDSSPP_H_INCLUDED


