#define SPACE_CRAFT_ID 0b1111111111
typedef union Primarry_Hrader
{
    unsigned char Primarry_Hrader_[6];
	
    struct
        {
            unsigned     char a0;
            unsigned     char a1;
            unsigned     char a2;
            unsigned     char a3;
            unsigned     char a4;
            unsigned     char a5;
        }ShiftRegBytes;

	struct Primary_Header_Fields
		{
			unsigned char Transfer_Frame_Version_Number:2;
			unsigned char Bypass_Flag:1;
			unsigned char Control_Command_Flag:1;
			unsigned char Reserved_Spare:2;
			unsigned char Spacecraft_Identifier:10;
			unsigned char Virtual_Channel_Identifier:6;
			unsigned char Frame_Length:10;			
			unsigned char Frame_Sequence_Number:8;  
		}Primary_Header_Fields;
		
}Primarry_Hrader;

typedef enum TransferFramVersionNumber
{
  StandardVersion=0b00,
  AnotherVersion=1
}TransferFramVersionNumber;

typedef enum Bypass_Flag
{
  Type-ATransfer_Frame=0,
  Type-BTransfer_Frame=1
}Bypass_Flag;

typedef enum Control_Command_Flag
{
  Type-DTransfer_Frame=0,
  Type-CTransfer_Frame=1
}Control_Command_Flag;
unsigned char CCSDSTeleCommandProtocolPHeadrGN (unsigned char Frame_Version_Number,Bypass_Flag BF ,Control_Command_Flag CF,
                                        unsigned short Spacecraft_Identifier,unsigned short Virtual_Channel_Identifier,unsigned short Frame_Length,unsigned char Frame_Sequence_Number,Primarry_Hrader * ph);
										
unsigned char  TELECOMMANDFRAMConstruction (Primarry_Hrader * ph,unsigned char *Data,int Data_Length,unsigned char * Data_output,unsigned short CRC);
