#include "game.h"
#include "ui_game.h"
#include "setup.h"

game::game(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::game)
{
    ui->setupUi(this);
    connect(ui->resetbutton,SIGNAL(clicked()),this,SLOT(on_resetbutton_clicked()));

    for(int k=0; k<16; k++){
        block[k].location=k+1;
        block[k].num=0;
    } /*初始化每一個block的位置跟儲存變數*/

    for(int r=0; r<4; r++){
        for(int c=0; c<4; c++){
            temcheck[r][c]=0;
        }
    } /*初始化遊戲過程所需的二維陣列(暫存)*/
    srand(time(NULL));
    checkMove=false;
}

game::~game()
{
    delete ui;
}

void game::Setpics(Set & b){
    switch (b.location){
    case 1:
        switch (b.num) {
                case 0:ui->b1->setPixmap(QPixmap(":/pics/pics0.PNG"));break;
                case 2:ui->b1->setPixmap(QPixmap(":/pics/pics2.jpg"));break;
                case 4:ui->b1->setPixmap(QPixmap(":/pics/pics4.jpg"));break;
                case 8:ui->b1->setPixmap(QPixmap(":/pics/pics8.jpg"));break;
                case 16:ui->b1->setPixmap(QPixmap(":/pics/pics16.jpg"));break;
                case 32:ui->b1->setPixmap(QPixmap(":/pics/pics32.jpg"));break;
                case 64:ui->b1->setPixmap(QPixmap(":/pics/pics64.jpg"));break;
                case 128:ui->b1->setPixmap(QPixmap(":/pics/pics128.jpg"));break;
                case 256:ui->b1->setPixmap(QPixmap(":/pics/pics256.jpg"));break;
                case 512:ui->b1->setPixmap(QPixmap(":/pics/pics512.jpg"));break;
                case 1024:ui->b1->setPixmap(QPixmap(":/pics/pics1024.jpg"));break;
                case 2048:ui->b1->setPixmap(QPixmap(":/pics/pics2048.jpg"));
                          ui->labelwin->setPixmap(QPixmap(":/pics/win.png"));
                          break;
        }
        break;
    case 2:
        switch (b.num) {
                case 0:ui->b2->setPixmap(QPixmap(":/pics/pics0.PNG"));break;
                case 2:ui->b2->setPixmap(QPixmap(":/pics/pics2.jpg"));break;
                case 4:ui->b2->setPixmap(QPixmap(":/pics/pics4.jpg"));break;
                case 8:ui->b2->setPixmap(QPixmap(":/pics/pics8.jpg"));break;
                case 16:ui->b2->setPixmap(QPixmap(":/pics/pics16.jpg"));break;
                case 32:ui->b2->setPixmap(QPixmap(":/pics/pics32.jpg"));break;
                case 64:ui->b2->setPixmap(QPixmap(":/pics/pics64.jpg"));break;
                case 128:ui->b2->setPixmap(QPixmap(":/pics/pics128.jpg"));break;
                case 256:ui->b2->setPixmap(QPixmap(":/pics/pics256.jpg"));break;
                case 512:ui->b2->setPixmap(QPixmap(":/pics/pics512.jpg"));break;
                case 1024:ui->b2->setPixmap(QPixmap(":/pics/pics1024.jpg"));break;
                case 2048:ui->b2->setPixmap(QPixmap(":/pics/pics2048.jpg"));
                          ui->labelwin->setPixmap(QPixmap(":/pics/win.png"));
                          break;
        }
        break;
    case 3:
        switch (b.num) {
                case 0:ui->b3->setPixmap(QPixmap(":/pics/pics0.PNG"));break;
                case 2:ui->b3->setPixmap(QPixmap(":/pics/pics2.jpg"));break;
                case 4:ui->b3->setPixmap(QPixmap(":/pics/pics4.jpg"));break;
                case 8:ui->b3->setPixmap(QPixmap(":/pics/pics8.jpg"));break;
                case 16:ui->b3->setPixmap(QPixmap(":/pics/pics16.jpg"));break;
                case 32:ui->b3->setPixmap(QPixmap(":/pics/pics32.jpg"));break;
                case 64:ui->b3->setPixmap(QPixmap(":/pics/pics64.jpg"));break;
                case 128:ui->b3->setPixmap(QPixmap(":/pics/pics128.jpg"));break;
                case 256:ui->b3->setPixmap(QPixmap(":/pics/pics256.jpg"));break;
                case 512:ui->b3->setPixmap(QPixmap(":/pics/pics512.jpg"));break;
                case 1024:ui->b3->setPixmap(QPixmap(":/pics/pics1024.jpg"));break;
                case 2048:ui->b3->setPixmap(QPixmap(":/pics/pics2048.jpg"));
                          ui->labelwin->setPixmap(QPixmap(":/pics/win.png"));
                          break;
        }
         break;
     case 4:
         switch (b.num) {
                case 0:ui->b4->setPixmap(QPixmap(":/pics/pics0.PNG"));break;
                case 2:ui->b4->setPixmap(QPixmap(":/pics/pics2.jpg"));break;
                case 4:ui->b4->setPixmap(QPixmap(":/pics/pics4.jpg"));break;
                case 8:ui->b4->setPixmap(QPixmap(":/pics/pics8.jpg"));break;
                case 16:ui->b4->setPixmap(QPixmap(":/pics/pics16.jpg"));break;
                case 32:ui->b4->setPixmap(QPixmap(":/pics/pics32.jpg"));break;
                case 64:ui->b4->setPixmap(QPixmap(":/pics/pics64.jpg"));break;
                case 128:ui->b4->setPixmap(QPixmap(":/pics/pics128.jpg"));break;
                case 256:ui->b4->setPixmap(QPixmap(":/pics/pics256.jpg"));break;
                case 512:ui->b4->setPixmap(QPixmap(":/pics/pics512.jpg"));break;
                case 1024:ui->b4->setPixmap(QPixmap(":/pics/pics1024.jpg"));break;
                case 2048:ui->b4->setPixmap(QPixmap(":/pics/pics2048.jpg"));
                          ui->labelwin->setPixmap(QPixmap(":/pics/win.png"));
                          break;
           }
           break;
     case 5:
         switch (b.num) {
                case 0:ui->b5->setPixmap(QPixmap(":/pics/pics0.PNG"));break;
                case 2:ui->b5->setPixmap(QPixmap(":/pics/pics2.jpg"));break;
                case 4:ui->b5->setPixmap(QPixmap(":/pics/pics4.jpg"));break;
                case 8:ui->b5->setPixmap(QPixmap(":/pics/pics8.jpg"));break;
                case 16:ui->b5->setPixmap(QPixmap(":/pics/pics16.jpg"));break;
                case 32:ui->b5->setPixmap(QPixmap(":/pics/pics32.jpg"));break;
                case 64:ui->b5->setPixmap(QPixmap(":/pics/pics64.jpg"));break;
                case 128:ui->b5->setPixmap(QPixmap(":/pics/pics128.jpg"));break;
                case 256:ui->b5->setPixmap(QPixmap(":/pics/pics256.jpg"));break;
                case 512:ui->b5->setPixmap(QPixmap(":/pics/pics512.jpg"));break;
                case 1024:ui->b5->setPixmap(QPixmap(":/pics/pics1024.jpg"));break;
                case 2048:ui->b5->setPixmap(QPixmap(":/pics/pics2048.jpg"));
                          ui->labelwin->setPixmap(QPixmap(":/pics/win.png"));
                          break;
         }
         break;
      case 6:
          switch (b.num) {
                case 0:ui->b6->setPixmap(QPixmap(":/pics/pics0.PNG"));break;
                case 2:ui->b6->setPixmap(QPixmap(":/pics/pics2.jpg"));break;
                case 4:ui->b6->setPixmap(QPixmap(":/pics/pics4.jpg"));break;
                case 8:ui->b6->setPixmap(QPixmap(":/pics/pics8.jpg"));break;
                case 16:ui->b6->setPixmap(QPixmap(":/pics/pics16.jpg"));break;
                case 32:ui->b6->setPixmap(QPixmap(":/pics/pics32.jpg"));break;
                case 64:ui->b6->setPixmap(QPixmap(":/pics/pics64.jpg"));break;
                case 128:ui->b6->setPixmap(QPixmap(":/pics/pics128.jpg"));break;
                case 256:ui->b6->setPixmap(QPixmap(":/pics/pics256.jpg"));break;
                case 512:ui->b6->setPixmap(QPixmap(":/pics/pics512.jpg"));break;
                case 1024:ui->b6->setPixmap(QPixmap(":/pics/pics1024.jpg"));break;
                case 2048:ui->b6->setPixmap(QPixmap(":/pics/pics2048.jpg"));
                          ui->labelwin->setPixmap(QPixmap(":/pics/win.png"));
                          break;
            }
            break;
       case 7:
           switch (b.num) {
                case 0:ui->b7->setPixmap(QPixmap(":/pics/pics0.PNG"));break;
                case 2:ui->b7->setPixmap(QPixmap(":/pics/pics2.jpg"));break;
                case 4:ui->b7->setPixmap(QPixmap(":/pics/pics4.jpg"));break;
                case 8:ui->b7->setPixmap(QPixmap(":/pics/pics8.jpg"));break;
                case 16:ui->b7->setPixmap(QPixmap(":/pics/pics16.jpg"));break;
                case 32:ui->b7->setPixmap(QPixmap(":/pics/pics32.jpg"));break;
                case 64:ui->b7->setPixmap(QPixmap(":/pics/pics64.jpg"));break;
                case 128:ui->b7->setPixmap(QPixmap(":/pics/pics128.jpg"));break;
                case 256:ui->b7->setPixmap(QPixmap(":/pics/pics256.jpg"));break;
                case 512:ui->b7->setPixmap(QPixmap(":/pics/pics512.jpg"));break;
                case 1024:ui->b7->setPixmap(QPixmap(":/pics/pics1024.jpg"));break;
                case 2048:ui->b7->setPixmap(QPixmap(":/pics/pics2048.jpg"));
                          ui->labelwin->setPixmap(QPixmap(":/pics/win.png"));
                          break;

           }
           break;
       case 8:
           switch (b.num) {
                case 0:ui->b8->setPixmap(QPixmap(":/pics/pics0.PNG"));break;
                case 2:ui->b8->setPixmap(QPixmap(":/pics/pics2.jpg"));break;
                case 4:ui->b8->setPixmap(QPixmap(":/pics/pics4.jpg"));break;
                case 8:ui->b8->setPixmap(QPixmap(":/pics/pics8.jpg"));break;
                case 16:ui->b8->setPixmap(QPixmap(":/pics/pics16.jpg"));break;
                case 32:ui->b8->setPixmap(QPixmap(":/pics/pics32.jpg"));break;
                case 64:ui->b8->setPixmap(QPixmap(":/pics/pics64.jpg"));break;
                case 128:ui->b8->setPixmap(QPixmap(":/pics/pics128.jpg"));break;
                case 256:ui->b8->setPixmap(QPixmap(":/pics/pics256.jpg"));break;
                case 512:ui->b8->setPixmap(QPixmap(":/pics/pics512.jpg"));break;
                case 1024:ui->b8->setPixmap(QPixmap(":/pics/pics1024.jpg"));break;
                case 2048:ui->b8->setPixmap(QPixmap(":/pics/pics2048.jpg"));
                          ui->labelwin->setPixmap(QPixmap(":/pics/win.png"));
                          break;
            }
            break;
      case 9:
          switch (b.num) {
                case 0:ui->b9->setPixmap(QPixmap(":/pics/pics0.PNG"));break;
                case 2:ui->b9->setPixmap(QPixmap(":/pics/pics2.jpg"));break;
                case 4:ui->b9->setPixmap(QPixmap(":/pics/pics4.jpg"));break;
                case 8:ui->b9->setPixmap(QPixmap(":/pics/pics8.jpg"));break;
                case 16:ui->b9->setPixmap(QPixmap(":/pics/pics16.jpg"));break;
                case 32:ui->b9->setPixmap(QPixmap(":/pics/pics32.jpg"));break;
                case 64:ui->b9->setPixmap(QPixmap(":/pics/pics64.jpg"));break;
                case 128:ui->b9->setPixmap(QPixmap(":/pics/pics128.jpg"));break;
                case 256:ui->b9->setPixmap(QPixmap(":/pics/pics256.jpg"));break;
                case 512:ui->b9->setPixmap(QPixmap(":/pics/pics512.jpg"));break;
                case 1024:ui->b9->setPixmap(QPixmap(":/pics/pics1024.jpg"));break;
                case 2048:ui->b9->setPixmap(QPixmap(":/pics/pics2048.jpg"));
                          ui->labelwin->setPixmap(QPixmap(":/pics/win.png"));
                          break;
            }
            break;
      case 10:
          switch (b.num) {
                case 0:ui->b10->setPixmap(QPixmap(":/pics/pics0.PNG"));break;
                case 2:ui->b10->setPixmap(QPixmap(":/pics/pics2.jpg"));break;
                case 4:ui->b10->setPixmap(QPixmap(":/pics/pics4.jpg"));break;
                case 8:ui->b10->setPixmap(QPixmap(":/pics/pics8.jpg"));break;
                case 16:ui->b10->setPixmap(QPixmap(":/pics/pics16.jpg"));break;
                case 32:ui->b10->setPixmap(QPixmap(":/pics/pics32.jpg"));break;
                case 64:ui->b10->setPixmap(QPixmap(":/pics/pics64.jpg"));break;
                case 128:ui->b10->setPixmap(QPixmap(":/pics/pics128.jpg"));break;
                case 256:ui->b10->setPixmap(QPixmap(":/pics/pics256.jpg"));break;
                case 512:ui->b10->setPixmap(QPixmap(":/pics/pics512.jpg"));break;
                case 1024:ui->b10->setPixmap(QPixmap(":/pics/pics1024.jpg"));break;
                case 2048:ui->b10->setPixmap(QPixmap(":/pics/pics2048.jpg"));
                          ui->labelwin->setPixmap(QPixmap(":/pics/win.png"));
                          break;
            }
            break;
      case 11:
          switch (b.num) {
                case 0:ui->b11->setPixmap(QPixmap(":/pics/pics0.PNG"));break;
                case 2:ui->b11->setPixmap(QPixmap(":/pics/pics2.jpg"));break;
                case 4:ui->b11->setPixmap(QPixmap(":/pics/pics4.jpg"));break;
                case 8:ui->b11->setPixmap(QPixmap(":/pics/pics8.jpg"));break;
                case 16:ui->b11->setPixmap(QPixmap(":/pics/pics16.jpg"));break;
                case 32:ui->b11->setPixmap(QPixmap(":/pics/pics32.jpg"));break;
                case 64:ui->b11->setPixmap(QPixmap(":/pics/pics64.jpg"));break;
                case 128:ui->b11->setPixmap(QPixmap(":/pics/pics128.jpg"));break;
                case 256:ui->b11->setPixmap(QPixmap(":/pics/pics256.jpg"));break;
                case 512:ui->b11->setPixmap(QPixmap(":/pics/pics512.jpg"));break;
                case 1024:ui->b11->setPixmap(QPixmap(":/pics/pics1024.jpg"));break;
                case 2048:ui->b11->setPixmap(QPixmap(":/pics/pics2048.jpg"));
                          ui->labelwin->setPixmap(QPixmap(":/pics/win.png"));
                          break;
          }
          break;
       case 12:
           switch (b.num) {
                case 0:ui->b12->setPixmap(QPixmap(":/pics/pics0.PNG"));break;
                case 2:ui->b12->setPixmap(QPixmap(":/pics/pics2.jpg"));break;
                case 4:ui->b12->setPixmap(QPixmap(":/pics/pics4.jpg"));break;
                case 8:ui->b12->setPixmap(QPixmap(":/pics/pics8.jpg"));break;
                case 16:ui->b12->setPixmap(QPixmap(":/pics/pics16.jpg"));break;
                case 32:ui->b12->setPixmap(QPixmap(":/pics/pics32.jpg"));break;
                case 64:ui->b12->setPixmap(QPixmap(":/pics/pics64.jpg"));break;
                case 128:ui->b12->setPixmap(QPixmap(":/pics/pics128.jpg"));break;
                case 256:ui->b12->setPixmap(QPixmap(":/pics/pics256.jpg"));break;
                case 512:ui->b12->setPixmap(QPixmap(":/pics/pics512.jpg"));break;
                case 1024:ui->b12->setPixmap(QPixmap(":/pics/pics1024.jpg"));break;
                case 2048:ui->b12->setPixmap(QPixmap(":/pics/pics2048.jpg"));
                          ui->labelwin->setPixmap(QPixmap(":/pics/win.png"));
                          break;
          }
          break;
       case 13:
           switch (b.num) {
                case 0:ui->b13->setPixmap(QPixmap(":/pics/pics0.PNG"));break;
                case 2:ui->b13->setPixmap(QPixmap(":/pics/pics2.jpg"));break;
                case 4:ui->b13->setPixmap(QPixmap(":/pics/pics4.jpg"));break;
                case 8:ui->b13->setPixmap(QPixmap(":/pics/pics8.jpg"));break;
                case 16:ui->b13->setPixmap(QPixmap(":/pics/pics16.jpg"));break;
                case 32:ui->b13->setPixmap(QPixmap(":/pics/pics32.jpg"));break;
                case 64:ui->b13->setPixmap(QPixmap(":/pics/pics64.jpg"));break;
                case 128:ui->b13->setPixmap(QPixmap(":/pics/pics128.jpg"));break;
                case 256:ui->b13->setPixmap(QPixmap(":/pics/pics256.jpg"));break;
                case 512:ui->b13->setPixmap(QPixmap(":/pics/pics512.jpg"));break;
                case 1024:ui->b13->setPixmap(QPixmap(":/pics/pics1024.jpg"));break;
                case 2048:ui->b13->setPixmap(QPixmap(":/pics/pics2048.jpg"));
                          ui->labelwin->setPixmap(QPixmap(":/pics/win.png"));
                          break;
           }
           break;
       case 14:
           switch (b.num) {
                case 0:ui->b14->setPixmap(QPixmap(":/pics/pics0.PNG"));break;
                case 2:ui->b14->setPixmap(QPixmap(":/pics/pics2.jpg"));break;
                case 4:ui->b14->setPixmap(QPixmap(":/pics/pics4.jpg"));break;
                case 8:ui->b14->setPixmap(QPixmap(":/pics/pics8.jpg"));break;
                case 16:ui->b14->setPixmap(QPixmap(":/pics/pics16.jpg"));break;
                case 32:ui->b14->setPixmap(QPixmap(":/pics/pics32.jpg"));break;
                case 64:ui->b14->setPixmap(QPixmap(":/pics/pics64.jpg"));break;
                case 128:ui->b14->setPixmap(QPixmap(":/pics/pics128.jpg"));break;
                case 256:ui->b14->setPixmap(QPixmap(":/pics/pics256.jpg"));break;
                case 512:ui->b14->setPixmap(QPixmap(":/pics/pics512.jpg"));break;
                case 1024:ui->b14->setPixmap(QPixmap(":/pics/pics1024.jpg"));break;
                case 2048:ui->b14->setPixmap(QPixmap(":/pics/pics2048.jpg"));
                          ui->labelwin->setPixmap(QPixmap(":/pics/win.png"));
                          break;
           }
           break;
       case 15:
           switch (b.num) {
                case 0:ui->b15->setPixmap(QPixmap(":/pics/pics0.PNG"));break;
                case 2:ui->b15->setPixmap(QPixmap(":/pics/pics2.jpg"));break;
                case 4:ui->b15->setPixmap(QPixmap(":/pics/pics4.jpg"));break;
                case 8:ui->b15->setPixmap(QPixmap(":/pics/pics8.jpg"));break;
                case 16:ui->b15->setPixmap(QPixmap(":/pics/pics16.jpg"));break;
                case 32:ui->b15->setPixmap(QPixmap(":/pics/pics32.jpg"));break;
                case 64:ui->b15->setPixmap(QPixmap(":/pics/pics64.jpg"));break;
                case 128:ui->b15->setPixmap(QPixmap(":/pics/pics128.jpg"));break;
                case 256:ui->b15->setPixmap(QPixmap(":/pics/pics256.jpg"));break;
                case 512:ui->b15->setPixmap(QPixmap(":/pics/pics512.jpg"));break;
                case 1024:ui->b15->setPixmap(QPixmap(":/pics/pics1024.jpg"));break;
                case 2048:ui->b15->setPixmap(QPixmap(":/pics/pics2048.jpg"));
                          ui->labelwin->setPixmap(QPixmap(":/pics/win.png"));
                          break;
            }
           break;
       case 16:
           switch (b.num) {
                case 0:ui->b16->setPixmap(QPixmap(":/pics/pics0.PNG"));break;
                case 2:ui->b16->setPixmap(QPixmap(":/pics/pics2.jpg"));break;
                case 4:ui->b16->setPixmap(QPixmap(":/pics/pics4.jpg"));break;
                case 8:ui->b16->setPixmap(QPixmap(":/pics/pics8.jpg"));break;
                case 16:ui->b16->setPixmap(QPixmap(":/pics/pics16.jpg"));break;
                case 32:ui->b16->setPixmap(QPixmap(":/pics/pics32.jpg"));break;
                case 64:ui->b16->setPixmap(QPixmap(":/pics/pics64.jpg"));break;
                case 128:ui->b16->setPixmap(QPixmap(":/pics/pics128.jpg"));break;
                case 256:ui->b16->setPixmap(QPixmap(":/pics/pics256.jpg"));break;
                case 512:ui->b16->setPixmap(QPixmap(":/pics/pics512.jpg"));break;
                case 1024:ui->b16->setPixmap(QPixmap(":/pics/pics1024.jpg"));break;
                case 2048:ui->b16->setPixmap(QPixmap(":/pics/pics2048.jpg"));
                          ui->labelwin->setPixmap(QPixmap(":/pics/win.png"));
                          break;
            }
            break;
    }
} /*圖片隨著儲存變數改變*/

void game::CheckScore(){
     int r,c; /*row&colum*/
     int i;
     int flag=0;

     switch (dir){
           case 0 : /*上*/
               for (c=0; c<4; c++){
                  for (r=0; r<3; r++){
                     if ((check[r][c] !=0 )&&(check[r][c]==check[r+1][c])){
                          check[r][c]=check[r][c]*2;
                          score+=check[r][c];
                          for (i=r+1; i<3; i++){
                               check[i][c]=check[i+1][c];
                          }
                          if(flag){
                              check[2][c]=0;
                          }
                          else{
                              check[3][c]=0;
                              flag++;
                          }
                      }
                   }
               }
               break;
           case 1 :  /*右*/
               for (r=0; r<4; r++){
                  for (c=3; c>0; c--){
                     if ((check[r][c] !=0 ) && (check[r][c] == check[r][c-1])){
                          check[r][c]*=2;
                          score+=check[r][c];
                          for (i=c-1; i>0; i--){
                               check[r][i]=check[r][i-1];
                          }
                          if(flag){
                              check[r][1]=0;
                          }
                          else{
                              check[r][0]=0;
                              flag++;
                          }
                      }

                   }
               }
               break;
           case 2 :  /*下*/
               for (c=0; c<4; c++){
                  for (r=3; r>0; r--){
                     if ((check[r][c] !=0 ) && (check[r][c] == check[r-1][c])){
                          check[r][c]*=2;
                          score+=check[r][c];
                          for (i=r-1; i>0; i--){
                               check[i][c]=check[i-1][c];
                          }
                          if(flag){
                            check[1][c]=0;
                          }
                          else{
                            check[0][c]=0;
                            flag++;
                          }
                      }
                  }
                }
               break;
           case 3 :  /*左*/
               for (r=0; r<4; r++){
                  for (c=0; c<3; c++){
                     if ((check[r][c] !=0 ) && (check[r][c] == check[r][c+1])){
                          check[r][c]*=2;
                          score+=check[r][c];
                          for (i=c+1; i<3; i++){
                               check[r][i]=check[r][i+1];
                          }
                          if(flag){
                            check[r][2]=0;
                          }
                          else{
                            check[r][3]=0;
                            flag++;
                          }
                      }
                  }
              }
      }
}

int game::ProcessGame(){
    int i,r,c;
    int rptr[4], cptr[4];

    switch (dir){
          case 0 :  /*上*/
              for (i=0; i<4; i++) rptr[i]=0;
              for (r=0; r<4; r++){
                 for (c=0; c<4; c++){
                    if (check[r][c]!=0){
                        temcheck[rptr[c]][c]=check[r][c];
                        rptr[c]++;
                    }
                 }
               }
              for(r=0; r<4; r++){
                  for(c=0; c<4; c++){
                      check[r][c]=temcheck[r][c];
                  }
              }

              CheckScore();
              i=0;
              for(r=0; r<4; r++){
                  for(c=0; c<4; c++){
                      if(block[i].num!=check[r][c]){
                          checkMove=true;
                      }
                      block[i].num=check[r][c];
                      i++;
                  }
              } /*reset block[].num*/
              result=GetNewNumber();
              str=QString::number(score,10);
              ui->score->setText(str); /*記分板*/
              for(i=0; i<16; i++){
                  Setpics(block[i]);
              }
              if (result==2){
                  ui->labellose->setPixmap(QPixmap(":/pics/lose.PNG"));
              } /*輸了的狀況就出現lose的畫面*/
              break;
          case 1 :  /*右*/
              for (i=0; i<4; i++) cptr[i]=3;
              for (r=0; r<4; r++){
                 for (c=3; c>-1; c--){
                    if (check[r][c] !=0){
                        temcheck[r][cptr[r]]=check[r][c];
                        cptr[r]--;
                     }
                 }
              }
              for(r=0; r<4; r++){
                  for(c=0; c<4; c++){
                      check[r][c]=temcheck[r][c];
                  }
              }

              CheckScore();
              i=0;
              for(r=0; r<4; r++){
                  for(c=0; c<4; c++){
                      if(block[i].num!=check[r][c]){
                          checkMove=true;
                      }
                      block[i].num=check[r][c];
                      i++;
                  }
              }
              result=GetNewNumber();
              str=QString::number(score,10);
              ui->score->setText(str);
              for(i=0; i<16; i++){
                  Setpics(block[i]);
              }
              if (result==2){
                  ui->labellose->setPixmap(QPixmap(":/pics/lose.PNG"));
              } /*輸了的狀況就出現lose的畫面*/
              break;
          case 2 :   /*下*/
              for (i=0; i<4; i++) rptr[i]=3;
              for (r=3; r>-1; r--){
                 for (c=0; c<4; c++){
                    if (check[r][c] !=0){
                        temcheck[rptr[c]][c]=check[r][c];
                        rptr[c]--;
                    }
                  }
              }
              for(r=0; r<4; r++){
                  for(c=0; c<4; c++){
                      check[r][c]=temcheck[r][c];
                  }
              }

              CheckScore();
              i=0;
              for(r=0; r<4; r++){
                  for(c=0; c<4; c++){
                      if(block[i].num!=check[r][c]){
                          checkMove=true;
                      }
                      block[i].num=check[r][c];
                      i++;
                  }
              }
              result=GetNewNumber();
              str=QString::number(score,10);
              ui->score->setText(str);
              for(i=0; i<16; i++){
                  Setpics(block[i]);
              }
              if (result==2){
                  ui->labellose->setPixmap(QPixmap(":/pics/lose.PNG"));
              } /*輸了的狀況就出現lose的畫面*/
              break;
          case 3 :   /*左*/
              for (i=0; i<4; i++) cptr[i]=0;
              for (r=0; r<4; r++){
                 for (c=0; c<4; c++){
                    if (check[r][c] !=0){
                        temcheck[r][cptr[r]]=check[r][c];
                        cptr[r]++;
                     }
                 }
              }
              for(r=0; r<4; r++){
                  for(c=0; c<4; c++){
                      check[r][c]=temcheck[r][c];
                  }
              }

              CheckScore();
              i=0;
              for(r=0; r<4; r++){
                  for(c=0; c<4; c++){
                      if(block[i].num!=check[r][c]){
                          checkMove=true;
                      }
                      block[i].num=check[r][c];
                      i++;
                  }
              }
              result=GetNewNumber();
              str=QString::number(score,10);
              ui->score->setText(str);
              for(i=0; i<16; i++){
                  Setpics(block[i]);
              }
              if (result==2){
                  ui->labellose->setPixmap(QPixmap(":/pics/lose.PNG"));
              } /*輸了的狀況就出現lose的畫面*/
              break;
         }
         return result;
}

void game::NewGameInit(){
     int newlocation; /*一開始產生的格子的位置*/
     int newnum; /*一開始產生的格子的數字*/
     score=0;

     newlocation=rand()%16+1;
     while(block[newlocation].num!=0){
           newlocation=rand()%16;
     } /*確認那格是不是空的*/
     newnum=rand()%2;

     if(newnum==0) newnum=2;
     else newnum=4; /*不是產生2就是4*/
     block[newlocation].num=newnum;
     Setpics(block[newlocation]);
} /*隨機產生位置&數字*/

int game::GetNewNumber(){
    int i;
    int r,c; /*row&column*/
    int ocp=0;
    int Newloc;
    int Newnum;
    if(checkMove==false){
        return 1;//1的狀況代表完全沒有動，沒動就不需要產生新的格子
    }

    /*如果有移動的話程式碼會繼續跑*/
    /*有移動的話就不可能全部的格子會填滿*/
    /*所以一定要產生新的格子*/
    /*產生完新的格子之後才要判斷有沒有滿*/

    Newloc=rand()%16;
    while(block[Newloc].num!=0){
        Newloc=rand()%16;
    } /*確認那格是不是空的*/
    Newnum=rand()%1;
    if (Newnum==0) Newnum=2;
    else Newnum=4;
    block[Newloc].num=Newnum;
    i=0;
    for(r=0; r<4; r++){
        for(c=0; c<4; c++){
            check[r][c]=block[i].num;
            i++;
        }
    } /*初始化遊戲過程所需的二維陣列*/

    for (r=0; r<4; r++){
        for(c=0; c<4; c++){
            if (check[r][c] != 0) ocp++;
        }
    }	/*16格全滿的狀況可能是輸了，也可能還有可以移動的空間*/

    if(ocp==16){
        for(r=0; r<4; r++){
            for(c=1; c<4; c++){
                if((check[r][c])==(check[r][c-1]))
                    return 0;
            }
        } /*判斷左右其中一個有無相同*/

        for(c=0; c<4; c++){
            for(r=1; r<4; r++){
                    if((check[r][c])==(check[r-1][c]))
                        return 0;
            }
        } /*判斷上下其中一個有無相同*/
        /*0的狀況是格子滿了，而且還有可以合併的格子*/
        return 2; /*2的況狀是滿了，而且沒有可合併的格子*/
    }/*判斷是不是還有可以移動的空間*/
    return 3;/*3的狀況代表有動而且格子沒有滿而且產生新的格子了*/
}

void game::keyPressEvent(QKeyEvent *event){
     if(event->type()==QEvent::KeyPress){
         int x=0;
         checkMove=false;
         for(int r=0; r<4; r++){
             for(int c=0; c<4; c++){
                 check[r][c]=block[x].num;
                 temcheck[r][c]=0;
                 x++;
             }
         } /*初始化遊戲過程所需的二維陣列*/
         switch (event->key())
         {
         case Qt::Key_Up:
              dir=0;  /*上*/
              ProcessGame();
              break;
         case Qt::Key_Right:
              dir=1;  /*右*/
              ProcessGame();
              break;
         case Qt::Key_Down:
              dir=2;  /*下*/
              ProcessGame();
              break;
         case Qt::Key_Left:
              dir=3;  /*左*/
              ProcessGame();
              break;
         }
     }
}

void game::Gamestart(){
     NewGameInit(); /*產生新遊戲*/
}

void game::on_resetbutton_clicked(){
    int k,r,c;
    for(k=0; k<16; k++){
        block[k].location=k+1;
        block[k].num=0;
    } /*初始化每一個block的位置跟儲存變數*/

    for(r=0; r<4; r++){
        for(c=0; c<4; c++){
            check[r][c]=0;
        }
    }

    for(r=0; r<4; r++){
        for(c=0; c<4; c++){
            temcheck[r][c]=0;
        }
    } /*初始化遊戲過程所需的二維陣列(暫存)*/
    srand(time(NULL));
    checkMove=false;
    for(k=0; k<16; k++){
        Setpics(block[k]);
    }
    Gamestart();
}
