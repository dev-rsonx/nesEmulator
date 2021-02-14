#include "cpu.hpp"
#include "mainMemory.hpp"

cpuStruct cpu;

void ADC(){};
void AND(){};
void ASL(){};
void BCC(){};
void BCS(){};
void BEQ(){};
void BIT(){};
void BMI(){};
void BNE(){};
void BPL(){};
void BRK(){std::cout<<"hello"<<std::endl;};
void BVC(){};
void BVS(){};
void CLC(){};
void CLD(){};
void CLI(){};
void CLV(){};
void CMP(){};
void CPX(){};
void CPY(){};
void DEC(){};
void DEX(){};
void DEY(){};
void EOR(){};
void INC(){};
void INX(){};
void INY(){};
void JMP(){};
void JSR(){};
void LDA(){};
void LDX(){};
void LDY(){};
void LSR(){};
void NOP(){};
void ORA(){};
void PHA(){};
void PHP(){};
void PLA(){};
void PLP(){};
void ROL(){};
void ROR(){};
void RIT(){};
void RTS(){};
void SBC(){};
void SEC(){};
void SED(){};
void SEI(){};
void STA(){};
void STX(){};
void STY(){};
void TAX(){};
void TAY(){};
void TSX(){};
void TXA(){};
void TXS(){};
void TYA(){};
//Illegal opcodes
void KIL(){};
void SLO(){};
void RLA(){};
void SRE(){};
void RTI(){};
void RRA(){};
void SAX(){};
void AHX(){};
void LAX(){};
void DCP(){};
void ISC(){};
void ANC(){};
void ALR(){};
void ARR(){};
void XAA(){};
void SHY(){};
void TAS(){};
void SHX(){};
void LAS(){};
void AXS(){};

//instruction funciton pointer array
void* instrPtr[256] = {
    (void*)&BRK,(void*)&ORA,(void*)&KIL,(void*)&SLO,(void*)&NOP,(void*)&ORA,(void*)&ASL,(void*)&SLO,(void*)&PHP,(void*)&ORA,(void*)&ASL,(void*)&ANC,(void*)&NOP,(void*)&ORA,(void*)&ASL,(void*)&SLO,
    (void*)&BPL,(void*)&ORA,(void*)&KIL,(void*)&SLO,(void*)&NOP,(void*)&ORA,(void*)&ASL,(void*)&SLO,(void*)&CLC,(void*)&ORA,(void*)&NOP,(void*)&SLO,(void*)&NOP,(void*)&ORA,(void*)&ASL,(void*)&SLO,
    (void*)&JSR,(void*)&AND,(void*)&KIL,(void*)&RLA,(void*)&BIT,(void*)&AND,(void*)&ROL,(void*)&RLA,(void*)&PLP,(void*)&AND,(void*)&ROL,(void*)&ANC,(void*)&BIT,(void*)&AND,(void*)&ROL,(void*)&RLA,
    (void*)&BMI,(void*)&AND,(void*)&KIL,(void*)&RLA,(void*)&NOP,(void*)&AND,(void*)&ROL,(void*)&RLA,(void*)&SEC,(void*)&AND,(void*)&NOP,(void*)&RLA,(void*)&NOP,(void*)&AND,(void*)&ROL,(void*)&RLA,
    (void*)&RTI,(void*)&EOR,(void*)&KIL,(void*)&SRE,(void*)&NOP,(void*)&EOR,(void*)&LSR,(void*)&SRE,(void*)&PHA,(void*)&EOR,(void*)&LSR,(void*)&ALR,(void*)&JMP,(void*)&EOR,(void*)&LSR,(void*)&SRE,
    (void*)&BVC,(void*)&EOR,(void*)&KIL,(void*)&SRE,(void*)&NOP,(void*)&EOR,(void*)&LSR,(void*)&SRE,(void*)&CLI,(void*)&EOR,(void*)&NOP,(void*)&SRE,(void*)&NOP,(void*)&EOR,(void*)&LSR,(void*)&SRE,
    (void*)&RTS,(void*)&ADC,(void*)&KIL,(void*)&RRA,(void*)&NOP,(void*)&ADC,(void*)&ROR,(void*)&RRA,(void*)&PLA,(void*)&ADC,(void*)&ROR,(void*)&ARR,(void*)&JMP,(void*)&ADC,(void*)&ROR,(void*)&RRA,
    (void*)&BVS,(void*)&ADC,(void*)&KIL,(void*)&RRA,(void*)&NOP,(void*)&ADC,(void*)&ROR,(void*)&RRA,(void*)&SEI,(void*)&ADC,(void*)&NOP,(void*)&RRA,(void*)&NOP,(void*)&ADC,(void*)&ROR,(void*)&RRA,
    (void*)&NOP,(void*)&STA,(void*)&NOP,(void*)&SAX,(void*)&STY,(void*)&STA,(void*)&STX,(void*)&SAX,(void*)&DEY,(void*)&NOP,(void*)&TXA,(void*)&XAA,(void*)&STY,(void*)&STA,(void*)&STX,(void*)&SAX,
    (void*)&BCC,(void*)&STA,(void*)&KIL,(void*)&AHX,(void*)&STY,(void*)&STA,(void*)&STX,(void*)&SAX,(void*)&TYA,(void*)&STA,(void*)&TXS,(void*)&TAS,(void*)&SHY,(void*)&STA,(void*)&SHX,(void*)&AHX,
    (void*)&LDY,(void*)&LDA,(void*)&LDX,(void*)&LAX,(void*)&LDY,(void*)&LDA,(void*)&LDX,(void*)&LAX,(void*)&TAY,(void*)&LDA,(void*)&TAX,(void*)&LAX,(void*)&LDY,(void*)&LDA,(void*)&LDX,(void*)&LAX,
    (void*)&BCS,(void*)&LDA,(void*)&KIL,(void*)&LAX,(void*)&LDY,(void*)&LDA,(void*)&LDX,(void*)&LAX,(void*)&CLV,(void*)&LDA,(void*)&TSX,(void*)&LAS,(void*)&LDY,(void*)&LDA,(void*)&LDX,(void*)&LAX,
    (void*)&CPY,(void*)&CMP,(void*)&NOP,(void*)&DCP,(void*)&CPY,(void*)&CMP,(void*)&DEC,(void*)&DCP,(void*)&INY,(void*)&CMP,(void*)&DEX,(void*)&AXS,(void*)&CPY,(void*)&CMP,(void*)&DEC,(void*)&DCP,
    (void*)&BNE,(void*)&CMP,(void*)&KIL,(void*)&DCP,(void*)&NOP,(void*)&CMP,(void*)&DEC,(void*)&DCP,(void*)&CLD,(void*)&CMP,(void*)&NOP,(void*)&DCP,(void*)&NOP,(void*)&CMP,(void*)&DEC,(void*)&DCP,
    (void*)&CPX,(void*)&SBC,(void*)&NOP,(void*)&ISC,(void*)&CPX,(void*)&SBC,(void*)&INC,(void*)&ISC,(void*)&INX,(void*)&SBC,(void*)&NOP,(void*)&SBC,(void*)&CPX,(void*)&SBC,(void*)&INC,(void*)&ISC,
    (void*)&BEQ,(void*)&SBC,(void*)&KIL,(void*)&ISC,(void*)&NOP,(void*)&SBC,(void*)&INC,(void*)&ISC,(void*)&SED,(void*)&SBC,(void*)&NOP,(void*)&ISC,(void*)&NOP,(void*)&SBC,(void*)&INC,(void*)&ISC,
};

//instruction opcode array
char instrCode[256][4] = {
    "BRK","ORA","KIL","SLO","NOP","ORA","ASL","SLO","PHP","ORA","ASL","ANC","NOP","ORA","ASL","SLO",
    "BPL","ORA","KIL","SLO","NOP","ORA","ASL","SLO","CLC","ORA","NOP","SLO","NOP","ORA","ASL","SLO",
    "JSR","AND","KIL","RLA","BIT","AND","ROL","RLA","PLP","AND","ROL","ANC","BIT","AND","ROL","RLA",
    "BMI","AND","KIL","RLA","NOP","AND","ROL","RLA","SEC","AND","NOP","RLA","NOP","AND","ROL","RLA",
    "RTI","EOR","KIL","SRE","NOP","EOR","LSR","SRE","PHA","EOR","LSR","ALR","JMP","EOR","LSR","SRE",
    "BVC","EOR","KIL","SRE","NOP","EOR","LSR","SRE","CLI","EOR","NOP","SRE","NOP","EOR","LSR","SRE",
    "RTS","ADC","KIL","RRA","NOP","ADC","ROR","RRA","PLA","ADC","ROR","ARR","JMP","ADC","ROR","RRA",
    "BVS","ADC","KIL","RRA","NOP","ADC","ROR","RRA","SEI","ADC","NOP","RRA","NOP","ADC","ROR","RRA",
    "NOP","STA","NOP","SAX","STY","STA","STX","SAX","DEY","NOP","TXA","XAA","STY","STA","STX","SAX",
    "BCC","STA","KIL","AHX","STY","STA","STX","SAX","TYA","STA","TXS","TAS","SHY","STA","SHX","AHX",
    "LDY","LDA","LDX","LAX","LDY","LDA","LDX","LAX","TAY","LDA","TAX","LAX","LDY","LDA","LDX","LAX",
    "BCS","LDA","KIL","LAX","LDY","LDA","LDX","LAX","CLV","LDA","TSX","LAS","LDY","LDA","LDX","LAX",
    "CPY","CMP","NOP","DCP","CPY","CMP","DEC","DCP","INY","CMP","DEX","AXS","CPY","CMP","DEC","DCP",
    "BNE","CMP","KIL","DCP","NOP","CMP","DEC","DCP","CLD","CMP","NOP","DCP","NOP","CMP","DEC","DCP",
    "CPX","SBC","NOP","ISC","CPX","SBC","INC","ISC","INX","SBC","NOP","SBC","CPX","SBC","INC","ISC",
    "BEQ","SBC","KIL","ISC","NOP","SBC","INC","ISC","SED","SBC","NOP","ISC","NOP","SBC","INC","ISC",
};

//addressing mode array
int instrMode[256] = {
    imp,inx,xxx,xxx,xxx,zpg,zpg,xxx,imp,imm,acc,xxx,xxx,abl,abl,xxx,
    rel,iny,xxx,xxx,xxx,zpx,zpx,xxx,imp,aby,xxx,xxx,xxx,abx,abx,xxx,
    abl,inx,xxx,xxx,zpg,zpg,zpg,xxx,imp,imm,acc,xxx,abl,abl,abl,xxx,
    rel,iny,xxx,xxx,xxx,zpx,zpx,xxx,imp,aby,xxx,xxx,xxx,abx,abx,xxx,
    imp,inx,xxx,xxx,xxx,zpg,zpg,xxx,imp,imm,acc,xxx,abl,abl,abl,xxx,
    rel,iny,xxx,xxx,xxx,zpx,zpx,xxx,imp,aby,xxx,xxx,xxx,abx,abx,xxx,
    imp,inx,xxx,xxx,xxx,zpg,zpg,xxx,imp,imm,acc,xxx,ind,abl,abl,xxx,
    rel,iny,xxx,xxx,xxx,zpx,zpx,xxx,imp,aby,xxx,xxx,xxx,abx,abx,xxx,
    xxx,inx,xxx,xxx,zpg,zpg,zpg,xxx,imp,xxx,imp,xxx,abl,abl,abl,xxx,
    rel,iny,xxx,xxx,zpx,zpx,zpy,xxx,imp,aby,imp,xxx,xxx,abx,xxx,xxx,
    imm,inx,imm,xxx,zpg,zpg,zpg,xxx,imp,imm,imp,xxx,abl,abl,abl,xxx,
    rel,iny,xxx,xxx,zpx,zpx,zpy,xxx,imp,aby,imp,xxx,abx,abx,aby,xxx,
    imm,inx,xxx,xxx,zpg,zpg,zpg,xxx,imp,imm,imp,xxx,abl,abl,abl,xxx,
    rel,iny,xxx,xxx,xxx,zpx,zpx,xxx,imp,aby,xxx,xxx,xxx,abx,abx,xxx,
    imm,inx,xxx,xxx,zpg,zpg,zpg,xxx,imp,imm,imp,xxx,abl,abl,abl,xxx,
    rel,iny,xxx,xxx,xxx,zpx,zpx,xxx,imp,aby,xxx,xxx,xxx,abx,abx,xxx
};

//instr cycles
int instrCyc[256] = {
    7,6,2,8,3,3,5,5,3,2,2,2,4,4,6,6,
    2,5,2,8,4,4,6,6,2,4,2,7,4,4,7,7,
    6,6,2,8,3,3,5,5,4,2,2,2,4,4,6,6,
    2,5,2,8,4,4,6,6,2,4,2,7,4,4,7,7,
    6,6,2,8,3,3,5,5,3,2,2,2,3,4,6,6,
    2,5,2,8,4,4,6,6,2,4,2,7,4,4,7,7,
    6,6,2,8,3,3,5,5,4,2,2,2,5,4,6,6,
    2,5,2,8,4,4,6,6,2,4,2,7,4,4,7,7,
    2,6,2,6,3,3,3,3,2,2,2,2,4,4,4,4,
    2,6,2,6,4,4,4,4,2,5,2,5,5,5,5,5,
    2,6,2,6,3,3,3,3,2,2,2,2,4,4,4,4,
    2,5,2,5,4,4,4,4,2,4,2,4,4,4,4,4,
    2,6,2,8,3,3,5,5,2,2,2,2,4,4,6,6,
    2,5,2,8,4,4,6,6,2,4,2,7,4,4,7,7,
    2,6,2,8,3,3,5,5,2,2,2,2,4,4,6,6,
    2,5,2,8,4,4,6,6,2,4,2,7,4,4,7,7,
};

//instr cycles after crossing page boundary 
int instrPageCyc[256] = {
    0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,
    1,1,0,0,0,0,0,0,0,1,0,0,1,1,0,0,
    0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,
    1,1,0,0,0,0,0,0,0,1,0,0,1,1,0,0,
    0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,
    1,1,0,0,0,0,0,0,0,1,0,0,1,1,0,0,
    0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,
    1,1,0,0,0,0,0,0,0,1,0,0,1,1,0,0,
    0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,
    1,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,
    0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,
    1,1,0,1,0,0,0,0,0,1,0,1,1,1,1,1,
    0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,
    1,1,0,0,0,0,0,0,0,1,0,0,1,1,0,0,
    0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,
    1,1,0,0,0,0,0,0,0,1,0,0,1,1,0,0,
};

int instrSize[256] = {
    1,2,1,2,2,2,2,2,1,2,1,2,3,3,3,3,
    2,2,1,2,2,2,2,2,1,3,1,3,3,3,3,3,
    3,2,1,2,2,2,2,2,1,2,1,2,3,3,3,3,
    2,2,1,2,2,2,2,2,1,3,1,3,3,3,3,3,
    1,2,1,2,2,2,2,2,1,2,1,2,3,3,3,3,
    2,2,1,2,2,2,2,2,1,3,1,3,3,3,3,3,
    1,2,1,2,2,2,2,2,1,2,1,2,3,3,3,3,
    2,2,1,2,2,2,2,2,1,3,1,3,3,3,3,3,
    2,2,2,2,2,2,2,2,1,2,1,2,3,3,3,3,
    2,2,1,2,2,2,2,2,1,3,1,3,3,3,3,3,
    2,2,2,2,2,2,2,2,1,2,1,2,3,3,3,3,
    2,2,1,2,2,2,2,2,1,3,1,3,3,3,3,3,
    2,2,2,2,2,2,2,2,1,2,1,2,3,3,3,3,
    2,2,1,2,2,2,2,2,1,3,1,3,3,3,3,3,
    2,2,2,2,2,2,2,2,1,2,1,2,3,3,3,3,
    2,2,1,2,2,2,2,2,1,3,1,3,3,3,3,3,
};


void fetch(){
    cpu.ip = cpu.pc; //instruction pointer points current instruction
    cpu.opcode = memRead(cpu.ip);
    cpu.pc += instrSize[cpu.opcode]; //program counter points next instruction
}
void decode(){
    cpu.addressingMode = instrMode[cpu.opcode]; //addressing mode
    cpu.operand1 = memRead(memRead(cpu.ip+1)); //operand 1 fetch
    cpu.operand2 = memRead(memRead(cpu.ip+2)); //operand 2 fetch
}
void execute(uint8_t opcode){
    //execute the instruction with a function pointer
    typedef void exec();
    exec *e = (exec*)(void*)instrPtr[opcode];
    e();
}