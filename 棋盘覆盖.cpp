#include <stdio.h>
#include <stdlib.h>
#include <math.h> 
#include <iostream>
using namespace std;



int num = 0;
int Matrix[100][100];
void chessBoard(int tr, int tc, int dr, int dc, int size);


int main()
{
    int size,r,c,row,col;
    int k; 
    cout<<"k:";
   	cin>>k;
   	size=pow(2,k);
    cout<<"special row,col:";
    cin>>row>>col;
    chessBoard(0,0,row,col,size);

    for (r = 0; r < size; r++)
    {
        for (c = 0; c < size; c++)
        {
            printf("%2d ",Matrix[r][c]);
        }
        printf("\n");
    }

    return 0;
}

void chessBoard(int tr, int tc, int dr, int dc, int size)
{
    if (size==1) 
    	return;
    int s = size/2;     //∑÷∏Ó∆Â≈Ã
    int t = ++num;      //L–Õπ«≈∆∫≈
    
    //◊Û…œΩ«
    if (dr < tr + s && dc < tc +s)                
    {
        chessBoard(tr,tc,dr,dc,s);
    }
    else           
    {
        //”√t∫≈L–Õπ«≈∆∏≤∏«”“œ¬Ω«
        Matrix[tr+s-1][tc+s-1] = t;
        //∏≤∏«∆‰”‡∑Ω∏Ò
        chessBoard(tr,tc,tr+s-1,tc+s-1,s);
    }
    
    //”“…œΩ«
    if (dr < tr + s && dc >= tc + s )           
    {
        chessBoard(tr,tc+s,dr,dc,s);
    }
    else            
    {
        //”√t∫≈L–Õπ«≈∆∏≤∏«◊Ûœ¬Ω«
        Matrix[tr+s-1][tc+s] = t;
        //∏≤∏«∆‰”‡∑Ω∏Ò
        chessBoard(tr,tc+s,tr+s-1,tc+s,s);
    }
    
     //◊Ûœ¬Ω«
    if (dr >= tr + s && dc < tc + s)
    {
        chessBoard(tr+s,tc,dr,dc,s);
    }
    else
    {
        //”√t∫≈L–Õπ«≈∆∏≤∏«”“…œΩ«
        Matrix[tr+s][tc+s-1] = t;
        //∏≤∏«∆‰”‡∑Ω∏Ò
        chessBoard(tr+s,tc,tr+s,tc+s-1,s);
    }
    
     //”“œ¬Ω«
    if (dr >= tr + s && dc >= tc + s)
    {
        chessBoard(tr+s,tc+s,dr,dc,s);
    }
    else
    {
        //”√t∫≈L–Õπ«≈∆∏≤∏«◊Û…œΩ«
        Matrix[tr+s][tc+s] = t;
        //∏≤∏«∆‰”‡∑Ω∏Ò
        chessBoard(tr+s,tc+s,tr+s,tc+s,s);
    }

}

