/***********************************************************************/
/*  Program Name: 3-asm_pass1_u.c                                      */
/*  This program is the part of SIC/XE assembler Pass 1.	  		   */
/*  The program only identify the symbol, opcode and operand 		   */
/*  of a line of the asm file. The program do not build the            */
/*  SYMTAB.			                                               	   */
/*  2019.12.13                                                         */
/*  2021.03.26 Process error: format 1 & 2 instruction use + 		   */
/***********************************************************************/
#include <string.h>
#include <math.h>
#include "3-asm_pass1_u.c"
#include "Trie.c"

#define INIT_LOCCTR 0X00

int main(int argc, char *argv[])
{
	int line_state;
	int line_count;
	int locctr_start = INIT_LOCCTR;
	int locctr = INIT_LOCCTR;
	LINE line;
	Trie *symbolTable = createTrie();

	if (argc < 2)
	{
		printf("Usage: %s fname.asm\n", argv[0]);
		return 0;
	}
	else
	{
		if (ASM_open(argv[1]) == NULL)
		{
			printf("File not found!!\n");
		}
		else
		{
			for (line_count = 1; (line_state = process_line(&line)) != LINE_EOF; line_count++)
			{
				if (line_state == LINE_ERROR)
				{
					printf("%06d : Error\n", line_count);
				}
				else if (line_state == LINE_COMMENT)
				{
					printf(".\n");
				}
				else if (line.code == OP_START)
				{
					locctr_start = locctr = atoi(line.operand1);
				}
				else if (line.code == OP_END)
				{
					break;
				}
				else
				{
					if (strlen(line.symbol) && searchTrie(symbolTable, line.symbol) == -1)
					{
						insertTrie(symbolTable, line.symbol, locctr);
					}

					// print location counter & symbol
					printf("%06X %-8s ", locctr, line.symbol);
					// print instruction
					if (line.fmt == FMT4)
					{
						printf("+%-8s", line.op);
					}
					else
					{
						printf("%-9s", line.op);
					}
					// print operand1
					if (line.operand1[0])
					{
						if (line.addressing == ADDR_INDIRECT)
						{
							printf("@%-s", line.operand1);
						}
						else if (line.addressing == ADDR_IMMEDIATE)
						{
							printf("#%-s", line.operand1);
						}
						else
						{
							printf("%-s", line.operand1);
						}
					}
					// print operand2
					if (line.operand2[0])
					{
						printf(", %-s", line.operand2);
					}
					printf("\n");

					if (line.fmt == FMT0)
					{
						//counting store memory
						int size = 0;
						if (line.code == OP_WORD || line.code == OP_RESW)
						{
							size = 3;
						}
						else if (line.code == OP_BYTE || line.code == OP_RESB)
						{
							size = 1;
						}

						if (line.operand1[0] == 'C')
						{
							size = size * (ceil((double)(strlen(line.operand1) - 3)) / size);
						}
						else if (line.operand1[0] != 'X')
						{
							size = size * atoi(line.operand1);
						}
						locctr += size;
					}
					else if (line.fmt == FMT1)
					{
						locctr += 1;
					}
					else if (line.fmt == FMT2)
					{
						locctr += 2;
					}
					else if (line.fmt == FMT3)
					{
						locctr += 3;
					}
					else if (line.fmt == FMT4)
					{
						locctr += 4;
					}
				}
			}
			ASM_close();
		}
	}
	printf("\n\nProgram Length : %06X\n", locctr - locctr_start);
	printTrie(symbolTable);
}
