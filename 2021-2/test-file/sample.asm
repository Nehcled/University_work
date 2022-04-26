COPY	START 	1000
FIRST	STL 	RETADR  .為了做二次跳轉subroutine，需要將用來儲存回傳執行位置的register L中的值記錄下來
CLOOP	JSUB 	RDREC 	.讀取輸入裝置
	LDA 	LENGTH	.將常放入register A 中做比較，如果為0代表上次的讀取已經讀取到檔案結尾所以不需要再次進入讀取迴圈
	COMP 	ZERO	.	
	JEQ 	ENDFIL	.
	JSUB 	WRREC	.寫入輸出裝置
	J 	CLOOP	.如果還有資料，則繼續迴圈
ENDFIL	LDA 	EOF	.在輸出的檔案結尾寫入EOF
	STA 	BUFFER	.把EOF存到BUFFER中
	LDA 	THREE	.EOF的長度為3
	STA 	LENGTH	.因此將LENGTH 設為 3 並再次調用輸出裝置
	JSUB	WRREC	
	LDL 	RETADR	.將之前站存的上一層的回傳位置從新LOAD回register中，以便調用RSUB時可以回到正確的位置
	RSUB
.
EOF	BYTE 	C'EOF'
THREE	WORD 	3
ZERO	WORD 	0
RETADR	RESW 	1
LENGTH	RESW 	1
BUFFER	RESB 	4096
	.
	.
.
RDREC	LDX 	ZERO
	LDA 	ZERO	.因為在使用RD讀取內容時會儲存到register A為了避免之後出現內容衝突，先將A初始化為0
RLOOP	TD 	INPUT 
	JEQ	RLOOP
	RD 	INPUT
	COMP	ZERO	.如果讀入字元為00(為ascii中的0，也就是結尾符號\0，但不確定跟EOF之間的關聯)
	JEQ	EXIT
	STCH 	BUFFER,X
	TIX	MAXLEN	.最大讀取長度4096BYTE
	JLT 	RLOOP
EXIT	STX	LENGTH	.將register X中的值記錄到LENGTH中，記錄到目前為止讀取的長度，作為下次開始的起點
	RSUB
.
INPUT	BYTE	X'F1'
MAXLEN	WORD	4096
	.
	.
.
WRREC	LDX	ZERO	.初始化register X的值為0，因為寫入的子程序是從buffer中讀取
WLOOP	TD	OUTPUT
	JEQ	WLOOP
	LDCH	BUFFER,X
	WD	OUTPUT
	TIX	LENGTH
	JLT	WLOOP
	RSUB
OUTPUT	BYTE	X'05'
	END	FIRST

