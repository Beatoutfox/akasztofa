#include <bits/stdc++.h>
#include <fstream>
#include<graphics.h>
#include <conio.h>
using namespace std;
int beolvas(char sz[100][100])
{
    char s[100];
    ifstream f("be.in");
    int i=0;
    while(!f.eof())
    {
        f>>sz[i];
        i++;
    }
    return i-1;
}
void akaszt(int x)
{
    line(50,50,250,50);
    line(50,50,50,450);
    line(250,50,250,100);
    line(10,450,90,450);
}
void vonalak(int h)
{
    int i,x=300;
    for (i=0;i<h;i++)
    {
        line(x,70,x+20,70);
        x=x+30;
    }
}
void betuki(char mc,int poz)
{
    char ki[3];
    ki[0]=mc;ki[1]='\0';
    settextstyle(8,0,3);
    outtextxy(300+30*(poz),40,ki);
}
void beturossz(char mc,int poz)
{
    char ki[3];
    ki[0]=mc;ki[1]='\0';
    settextstyle(8,0,3);
    setcolor(4);
    outtextxy(150+30*(poz),375,ki);
    setcolor(15);
}
void hiba(int y)
{
    switch(y)
    {
        case 1: {circle(250,130,30);break;}
        case 2: {line(230,120,240,130);
                line(240,120,230,130);break;}
        case 3: {line(260,120,270,130);
                line(270,120,260,130);break;}
        case 4: {arc(220,125,90,270,5);break;}
        case 5: {arc(280,125,270,90,5);break;}
        case 6: {line(235,140,265,140);
                line(255,140,255,150);
                arc(255,140,180,360,10);
                break;}
        case 7: {line(250,160,250,180);break;}
        case 8: {ellipse(250,230,0,360,40,50);break;}
        case 9: {line(220,198,180,265);break;}
        case 10: {line(280,198,320,265);break;}
        case 11: {line(245,278,205,355);break;}
        case 12: {line(255,278,295,355);break;}

    }
}
void tulelte()
{
    circle(250,225,30);
    circle(237,217,7);
    circle(263,217,7);
    arc(220,220,90,270,5);
    arc(280,220,270,90,5);
    arc(250,220,230,320,20);
    line(250,255,250,275);
    ellipse(250,325,0,360,40,50);
    line(218,290,175,370);
    line(282,290,325,370);
    line(245,378,205,450);
    line(255,378,295,450);
}

void jtkvg(int i)
{
    if (i==0 || i!=12)
    {cleardevice();
    settextstyle(8,0,12);setcolor(2);
    outtextxy(500,300,"NYERTEL!");getch();}
    else{
    cleardevice();
    settextstyle(8,0,12);setcolor(4);
    outtextxy(400,300,"VESZTETTEL!");getch();}
    cleardevice();
    settextstyle(8,0,12);setcolor(15);
    outtextxy(400,300,"JATEK VEGE!");
    getch();
}
int main()
{
    int gd = DETECT, gm, x, y, color, angle = 0;
   struct arccoordstype a, b;
   initgraph(&gd, &gm, "");
    srand(time(0));
    char sz[100][100],s[100],be,v1[100]={'.'},v2[100]={'.'};
    int k,i,j=1,h,p=0,r=0;
    h=beolvas(sz);
    k=rand()%h+0;

    strcpy(s,sz[k]);
    h=strlen(s);
    akaszt(i);
    vonalak(h);
    bool ok=false;
    while (ok==false)
    {
        cout<<endl<<"Betu: ";
        be=getch();
        cout<<be;
        cout<<endl;
        if (strchr(s,be))
        {
                cout<<"jo a tipped";cout<<(char)7;

            if (strchr(v1,be))
               {
                   cout<<"de sajnos ez a betu mar volt.";
               }
            else
            for(i=0;i<=strlen(s);i++)
            {
                if (s[i]==be){
                    betuki(be,i);
                    v1[p]=be;
                    p++;
                }
            }
        }
        else
        {
            cout<<"Nincs benne a szoban";
            if (strchr(v2,be))
                {cout<<"de mar volt.";
                }
            else{
            v2[r]=be;
            beturossz(be,r);
            hiba(r+1);
            r++;}
        }
        if (p==strlen(s))
            {
                ok=true;cout<<endl<<"Eltalaltad!";
            }
        if (r==12)
            {
                ok=true;cout<<endl<<"Meghaltal!";
            }
    }
    if (r==0)
        tulelte();
    cout<<endl<<"JATEK VEGE!";
    getch();
    jtkvg(r);
    closegraph();
    return 0;
}
