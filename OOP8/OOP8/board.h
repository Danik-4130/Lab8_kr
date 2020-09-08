using namespace std;
enum KeyValue{
    ENTER = 13,
    UP = 72,
    DOWN = 80,
    LEFT  = 75,
    RIGHT = 77,
};
enum ConsoleColor
{
    	Black         = 0,
		Blue          = 1,
		Green         = 2,
		Cyan          = 3,
		Red           = 4,
		Magenta       = 5,
		Brown         = 6,
		LightGray     = 7,
		DarkGray      = 8,
		LightBlue     = 9,
		LightGreen    = 10,
		LightCyan     = 11,
		LightRed      = 12,
		LightMagenta  = 13,
		Yellow        = 14,
		White         = 15
};
void SetColor(ConsoleColor text, ConsoleColor background)
{
    HANDLE StdOut = GetStdHandle(STD_OUTPUT_HANDLE);
    SetConsoleTextAttribute(StdOut, (WORD)((background << 4) | text));
}
void gotoXY(int x,int y){
    COORD c = {x,y};
    HANDLE StdOut = GetStdHandle(STD_OUTPUT_HANDLE);
    SetConsoleCursorPosition(StdOut,c);
}
class board{
	
void clear_pos(int i,int j){
    gotoXY(i,j);
    cout << " ";
}
    char symbols[3][3];
    int current_x = 0;
    int current_y = 0;
public:
    bool board_is_full(){
        for(int i = 0 ; i < 3;i++){
            for(int j = 0; j < 3;j++){
                if(symbols[i][j] == ' ') return false;
            }
        }
        return true;
    }
    bool is_empty_position(int a,int b){
        return symbols[a][b] == ' ';
    }
    void resetXY(){
         current_x = 0;
         current_y = 0; 
    }
    void setChar(int a,int b,char s){
        symbols[a][b] = s;
    }
    void init(){
        for(int i = 0; i < 3;i++){
            for(int j = 0;j < 3;j++){
                symbols[i][j] = ' ';
            }
        }
    }
    void ShowBoard(int position){
        SetColor(White,Black);
        gotoXY(position,3);
        cout << "_______________";
        gotoXY(position,4);
        cout << "|    |    |    |";
        gotoXY(position,5);
        cout << "|____|____|____|";
        
        gotoXY(position,6);
        cout << "|    |    |    |";
        gotoXY(position,7);
        cout << "|____|____|____|";
        
        gotoXY(position,8);
        cout << "|    |    |    |";
        gotoXY(position,9);
        cout << "|____|____|____|";
    }
    void ShowValues(int a,int b,int c){
        //Первая линия
        
        gotoXY(a,4); cout << symbols[0][0]; //Первый символ
        gotoXY(b,4); cout << symbols[0][1]; //Второй символ
        gotoXY(c,4); cout << symbols[0][2]; //Третий символ
        
        //вторая линия и тд
        
        gotoXY(a,6); cout << symbols[1][0]; 
        gotoXY(b,6); cout << symbols[1][1]; 
        gotoXY(c,6); cout << symbols[1][2]; 
        
        //Третья линия
        
        gotoXY(a,8); cout << symbols[2][0];
        gotoXY(b,8); cout << symbols[2][1]; 
        gotoXY(c,8); cout << symbols[2][2]; 
    }
    int win(){
        //Проверка вертикальной линии сверху
    if(symbols[0][0] == symbols[0][1] and symbols[0][1] == symbols[0][2]){
        if(symbols[0][0] == '0') return 2;
       else if(symbols[0][0] == 'X') return 1;
    }
    //Проверка вертикальной линии по центру
   else if(symbols[1][0] == symbols[1][1] and symbols[1][0] == symbols[1][2]){
        if(symbols[1][0] == '0') return 2;
       else if(symbols[1][0] == 'X') return 1;
    }
    //Проверка вертикальной линии снизу
    else if(symbols[2][0] == symbols[2][1] and symbols[2][1] == symbols[2][2]){
        if(symbols[2][0] == '0') return 2;
        else if(symbols[2][0] == 'X') return 1;
    }
    //Проверка левой горизонтальной линии 
    else if(symbols[0][0] == symbols[1][0] and symbols[1][0] == symbols[2][0]){
        if(symbols[0][0] == '0') return 2;
        else if(symbols[0][0] == 'X') return 1;
    }
    //Проверка центральной горизонтальной линии
    else if(symbols[0][1] == symbols[1][1] and symbols[1][1] == symbols[2][1]){
        if(symbols[0][1] == '0') return 2;
        else if(symbols[0][1] == 'X') return 1;
    }
    //Проверка правой горизонтальной линии
    else if(symbols[0][2] == symbols[1][2] and symbols[0][2] == symbols[2][2]){
        if(symbols[0][2] == '0') return 2;
        else if(symbols[0][2] == 'X') return 1;
    }
    //Проверка 1,5,9
    else if(symbols[0][0] == symbols[1][1] and symbols[1][1] == symbols[2][2]){
        if(symbols[0][0] == '0') return 2;
        else if(symbols[0][0] == 'X') return 1;
    }
    //Проверка 3,5,7
    else if(symbols[0][2] == symbols[1][1] and symbols[1][1] == symbols[2][0]){
        if(symbols[0][2] == '0') return 2;
        else if(symbols[0][2] == 'X') return 1;
    }
    //Если ничего не исполнилось 
        return 0;
    }
    void input(char in){
        int x = 22;
        int y = 4;
        system("cls");
        ShowBoard(20);
        if(in == 'X')
            SetColor(Green,Black);
        else 
            SetColor(LightRed,Black);
        KeyValue key;
        gotoXY(x,y);
        cout << in;
        for(int i = 0;i < 41;i++){
            gotoXY(50,i);
            SetColor(Yellow,Black);
            cout << "|";
        }
        gotoXY(20,1);
        cout << "Board for values";
        gotoXY(60,1);
        cout << "Board for result";
        for(int i = 0; i < 120;i++){
            gotoXY(i,15);
            if(i!=50)
            cout << "_";
        }
        gotoXY(20,17);
        cout << "Some Values";
        gotoXY(80,17);
        cout << "Instructions";
        gotoXY(65,19);
        SetColor(LightGreen,Black);
        cout << "Left : ->";
        gotoXY(65,21);
        cout << "Right : <-";
        gotoXY(65,23);
        cout << "Up : \/\\";
        gotoXY(65,25);
        cout << "Down : \\\/";
        gotoXY(65,27);
        cout << "Enter value (X / 0) : ENTER";
		
        while(true){
            SetColor(LightGreen,Black);
            gotoXY(20,20);
            cout << "Current X : " << current_x;
            gotoXY(20,22);
            cout << "Current Y : " << current_y;
            gotoXY(20,24); cout << "                          ";
            gotoXY(20,24);
            cout.setf(ios_base::boolalpha);
            cout << "Empty : " << is_empty_position(current_x,current_y);
            SetColor(White,Black);
            ShowBoard(60);
            ShowValues(62,67,72);
            SetColor(White,Black);
            if(in == 'X')
            SetColor(Green,Black);
            else 
            SetColor(LightRed,Black);
            int(key)=(int)_getch();
            if(key == LEFT){
                clear_pos(x,y);
                if(x == 22 and y > 4){
                    x = 32;
                    y-=2;
                }
                else x-=5;
                if(current_y == 0 and current_x > 0){
                    current_y = 2;
                    current_x--;
                }
                else if(current_y > 0) current_y--;
            }
            if(key == UP and y != 4){
                clear_pos(x,y);
                y-=2;
                current_x--;
            }
            if(key == DOWN and y !=8){
                clear_pos(x,y);
                y+=2;
                current_x++;
            }
            if(key == RIGHT){
                clear_pos(x,y);
                if(x == 32 and y < 8){
                    x = 22;
                    y+=2;
                }
                else x+=5;
                if(current_y == 2 and current_x < 2){
                    current_y = 0;
                    current_x++;
                }
                else if(current_y != 2) current_y++;
            }
            if(key == ENTER){
                if(symbols[current_x][current_y] == ' '){
                    symbols[current_x][current_y] = in;
                    resetXY();
                    break;
                }
                else 
                    continue;
            }
            if(x < 22) x = 22;
            if(x > 32) x = 32;
            gotoXY(x,y);
            cout << in;
        }
    }
};