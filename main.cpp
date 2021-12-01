#include<graphics.h>
#include<iostream>
#include<conio.h>
#include<windows.h>
#include <sstream>
#include<string>
#include<cstdlib>
#include<ctime>

using namespace std;
char ch[25][8]={"00","10","20","30","40","50","60","70","80","90","100","110","120","130","140","150"};
int random[25],posy=0,posx=25,i;


void layout()
{
    rectangle(5, 5, 635, 370);  // outer box
    rectangle(10, 10, 630, 365);    // inner box

    rectangle(10, 390, 300, 440);    // cg mini project box

    rectangle(335, 390, 630, 440);  // ball catching game box

    settextstyle(BOLD_FONT, HORIZ_DIR, 3);
    outtextxy(15,400," BALL CATCHING GAME");

    settextstyle(BOLD_FONT, HORIZ_DIR, 2);
    outtextxy(360,400,"Laukik-Sahil-Saatvik");
}

int main()
{

    int gd=DETECT;
    int gm,score=0;
    initgraph(&gd,&gm,"C:\\TURBOC3\\BGI");
    //char msg[100];

    int semiposx=325, lineposx=325,speed = 10;
    int k=1,m=0,j=0,n=16,fall=5;

while(j<n)
   {
        layout();
        arc(semiposx,315 , 180, 0, 50);
        line(lineposx-50, 315, lineposx+50, 315);
        setfillstyle(SOLID_FILL,14);
        floodfill(semiposx,320,WHITE);

        if(GetAsyncKeyState(VK_LEFT))
        {
            semiposx-=speed;
            lineposx-=speed;
            if(semiposx<=40)
            {
                semiposx=570;
                lineposx=570;
            }
        }

        if(GetAsyncKeyState(VK_RIGHT))
        {
            semiposx+=speed;
            lineposx+=speed;
            if(semiposx>=590)
            {
                semiposx=60;
                lineposx=60;
            }
        }

        srand((unsigned)time(NULL));
        while(k>m)
        {
            for (i = 1; i < 25; i++)
            {
                random[i] = 50+ rand() % 500;
            }
            m=k;
        }

        posx=50+random[j];
        circle(posx,posy,15);
        setfillstyle(SOLID_FILL,15);
        floodfill(posx,posy,WHITE);
        posy=posy+fall;
        if(posy>=350)
        {
            posy=0;
            j++;
            k++;
            goto label;
        }
        if((lineposx-50<=posx) && (posx<=lineposx+50) && (posy==315))
        {
            score++;
            //cout<< "a\n";
            if(score>=5)
            {
                fall=7;
               // cout << "b\n";
            }
            if(score>=10)
            {
                fall=9;
                //cout<< "c\n";
            }
            posy=0;
            j++;
            k++;
        }


        /*if((score>15)&&(score<=20))
        {
            fall=10;
        }*/
        if(j==(n-1))
        {
            label:
            outtextxy(250,150," GAME OVER");
            outtextxy(250,190,"SCORE:");
            outtextxy(340,190,ch[score]);
            if (score==15){
                outtextxy(250,230,"   GGEZ   ");
            }
            delay(10000);
            return 0;
        }
        setfillstyle(SOLID_FILL, 1);
        floodfill(0,0,WHITE);
        delay(15);
        cleardevice();
    }
    return 0;
}
