#include <SFML/Graphics.hpp>
#include<SFML/Audio.hpp>
#include <time.h>
#include "menu.h"
#include "player.h"
#include"Bullet.h"
#include"Alpha.h"
#include"Beta.h"
#include"Gamma.h"
#include"Dragon.h"
#include"Monster.h"
#include"Powerup.h"
#include"dragonfire.h"
#include"live.h"
#include<cstdlib>
#include<ctime>
#include"danger.h"
using namespace sf;
const char title[] = "Space Shooter - OOP Project, Fall-24"; 
class Game
{

    private:
    Sprite background; //Game background sprite
    Sprite font0;
    Texture font0t;
    Sprite font1;
    Texture font1t;
    Sprite font2;
    Texture font2t;
    Sprite font3;
    Texture font3t;
    Sprite font20;
    Texture font20t; 
    Sprite font21;
    Texture font21t;
    Sprite font22;
    Texture font22t;
    Sprite font23;
    Texture font23t;
    Sprite font24;
    Texture font24t;  
    Sprite instruction;
    Texture instructiont;  
    Sprite sidedisplay;
    Texture sidedisplayt;  
    Sprite mbeam;
    Texture mbeamt;        
    Texture bg_texture;
    Texture bulletlrt;
    Texture bulletrrt;
    Texture pbulletlrt;
    Texture pbulletrrt;  
    Texture paddont;  
    Sprite paddon;
    Sprite pshield;
    Texture pshieldt;
    Font font;
    Text text;
    Font fontl;
    Text textl;  
    Sprite level11;
    Texture level11t;

    Player* p; //player 
    Enemy **en;
    Bullet* bullets[20];
    dragonfire* dragonfire1[1000];
    Powerup* powerbullets[20];
    menu* m;   
    live* addonlive;
    danger* dan;
    /////////////////area of integer specially retateded to check and time
    float bullettimer = 0; //Timer to track when to fire next bullet
    float pbullettimer = 0;
    float dbullettimer=0;
    float levelctimer=0;
    float dantimer=0;
    float monstertimer =0;
    float dragontimer=0;   
    float paddontimer=0;  
    float laddontimer=0;
    int laddonrand=0;  
    const float bulletInterval = 0.3;
    const float pbulletinterval = 0.6;
    const float dbulletinterval = 0.00999;
    int ac=0;
    int pbcheck2=0,bcheck2=0,dbcheck2=0;//this is bullet check
    int rotatecheck=0;  
    int rotatec=0;  
    int alphan=30,betan=30,gamman=30;
    int bullet_hit_enemy=0;
    int lcheck=0;
    int bulletnumber=20;
    int nextlevel=0;
    bomb* bomba[200];
    int lives=3;
    int monsterrand=0;
    int dragonrand=0;
    int monsterfirstc=0;
    int dragonfirstc=0;
    int laddoncfirst=0;
    int danrand=0;
    int daddoncfirst=0;
////////////////////////////
    float timer=0;
    int score=0;
    int a=0;
    int enterc=0;
    int inst=0;
    int Monstermc=0;
    int bombloopcount=0;
    int bdcount=0;
    int bulletrotate=0;
    int bulletrotatecl=0,bulletrotatecr=0;
    int pbulletrotate=0;
    int pbulletrotatecl=0,pbulletrotatecr=0;    
    int dragonp=0;
    int dcheck=0;
    int nextlevelcount=0;
    int paddonrand=0;
    int fireaddonc=0;
    int rotatec1=0,rotatec2=0;
    int paddoncfirst=0;
    int leveldis=0;
    int levelgc=0;
    ////intialization of all variable array
    float* timerbt;
    int* erand;
    int* bulletrotatearrayl;
    int* bulletrotatearrayr;
    int* pbulletrotatearrayl;
    int* pbulletrotatearrayr; 
    float shield=0;
    int shieldc=0;
    
    /////////////////////

    


    public:

    Game(){

      level11t.loadFromFile("img/New Project (17).png");
      level11.setTexture(level11t);
      level11.setPosition(-70,20);


      pshieldt.loadFromFile("img/Daco_5504780.png");
      pshield.setTexture(pshieldt);
      pshield.setPosition(2000,1000);
      pshield.setScale(0.2,0.2);

      dan=new danger("img/pngwing.com (2) (1).png");
      addonlive=new live("img/pill_blue.png");
      paddont.loadFromFile("img/bold_silver.png");
      paddon.setTexture(paddont);
      paddon.setPosition(2000,-100);
      timerbt=new float[alphan];
      erand=new int[alphan];
      bulletrotatearrayl=new int[bulletnumber];
      bulletrotatearrayr=new int[bulletnumber];
      pbulletrotatearrayl=new int[bulletnumber];
      pbulletrotatearrayr=new int[bulletnumber]; 
      ////font load
      font.loadFromFile("img/DragonHunter-9Ynxj.otf");
      fontl.loadFromFile("img/DragonHunter-9Ynxj.otf"); 
      ///we import the player image
      p=new Player("img/player_ship.png");
      m=new menu("img/desktop-1280x1024.jpg");
      for(int i=0;i<200;i++)
        bomba[i]=new bomb("img/enemy_laser.png");
      for(int i=0;i<200;i++){
        bomba[i]->spritee().setPosition(1000,1000);
        bomba[i]->spritee().setScale(0.08,0.08);
      }

      ////create enemy image
      en=new Enemy*[5];
      en[0]=new Alpha[alphan];
      en[1]=new Beta[betan];
      en[2]=new Gamma[gamman];
      en[3]=new Monster;
      en[4]=new Dragon;

      /////inport of alpha
      for(int i=0;i<alphan;i++){
        en[0][i].setimage("img/enemyRed1.png");
        en[0][i].eneimg().setScale(0.55,0.55);
        en[0][i].eneimg().setPosition(2000,1000);   
      }
      /////import of beta
      for(int i=0;i<betan;i++){
        en[1][i].setimage("img/enemyRed2.png");
        en[1][i].eneimg().setScale(0.55,0.55);
        en[1][i].eneimg().setPosition(2000,1000);   
      }
      /////import of gamma
      for(int i=0;i<gamman;i++){
        en[2][i].setimage("img/enemyRed3.png");
        en[2][i].eneimg().setScale(0.55,0.55);
        en[2][i].eneimg().setPosition(2000,1000);  
      }
      ///import and set image of background
      bg_texture.loadFromFile("walpaper.jpg");
      background.setTexture(bg_texture);
      /////////these are the diffrent selected pages and there types 
      font0t.loadFromFile("img/New Project (0).png");
      font0.setTexture(font0t); 
      font0.setPosition(-40,0);
      font1t.loadFromFile("img/New Project (1).png");
      font1.setTexture(font1t);
      font1.setPosition(-40,0); 
      font2t.loadFromFile("img/New Project (2).png");
      font2.setTexture(font2t); 
      font2.setPosition(-40,0);
      font3t.loadFromFile("img/New Project (3).png");
      font3.setTexture(font3t); 
      font3.setPosition(-40,0);
      font20t.loadFromFile("img/New Project2 (0).png");
      font20.setTexture(font20t); 
      font20.setPosition(-40,0);
      font21t.loadFromFile("img/New Project2 (1).png");
      font21.setTexture(font21t); 
      font21.setPosition(-40,0);
      font22t.loadFromFile("img/New Project2 (2).png");
      font22.setTexture(font22t); 
      font22.setPosition(-40,0);
      font23t.loadFromFile("img/New Project2 (3).png");
      font23.setTexture(font23t); 
      font23.setPosition(-40,0);
      font24t.loadFromFile("img/New Project2 (4).png");
      font24.setTexture(font24t); 
      font24.setPosition(-40,0);
      instructiont.loadFromFile("img/New Project (6).png");
      instruction.setTexture(instructiont); 
      instruction.setPosition(-80,20);
      sidedisplayt.loadFromFile("img/sidedisplay.png");
      sidedisplay.setTexture(sidedisplayt); 
      sidedisplay.setScale(0.7, 0.7);
      sidedisplay.setPosition(185,0);
      addonlive->powerimg().setPosition(2000,-100);
      ///import bullet sprite
      for (int i = 0; i < 20; i++) {
        bullets[i] = new Bullet("img/fire01.png");
      bullets[i]->bspritee().setPosition(-1000,-1000);
      }
      for (int i = 0; i < 1000; i++) {
        dragonfire1[i] = new dragonfire("img/dragonball.png");
      dragonfire1[i]->bsprite.setPosition(-1000,-1000);
      dragonfire1[i]->bsprite.setScale(0.06,0.06);
      }
      bulletlrt.loadFromFile("img/fire01 (1).png"); 
      bulletrrt.loadFromFile("img/fire01 (2).png");      
      //bullets[i]->bsprite.setScale(0.1, 0.1);      
       
      for (int i = 0; i < 20; i++) {
        powerbullets[i] = new Powerup("img/fire01 (3).png");
        powerbullets[i]->powerimg().setPosition(-1000,-1000);
      }
      pbulletlrt.loadFromFile("img/fire01 (3) (1).png"); 
      pbulletrrt.loadFromFile("img/fire01 (3) (2).png");   
      //set first the position of the monster
      en[3][0].setimage("img/monster1.png");
      en[3][0].eneimg().setScale(0.6,0.6);
      en[3][0].eneimg().setPosition(2000,1000);
      mbeamt.loadFromFile("img/mbeam.png");
      mbeam.setTexture(mbeamt); 
      mbeam.setScale(0.8,0.8);  
      mbeam.setPosition(2000,1000);
      dan->powerimg().setPosition(2000,-100);
      dan->powerimg().setScale(0.5,0.5);
      ////set the postion and intialize dragon
      en[4][0].setimage("img/dragon0.png");
      en[4][0].eneimg().setScale(0.5,0.5);
      en[4][0].eneimg().setPosition(200,-20);

    }

    void start_game()
    {
      srand(time(0));
      RenderWindow window(VideoMode(850,780), title);
      Clock clock,clockmove;
      float timermove=0;


      monsterrand=rand()%10+10;
      dragonrand=rand()%10+10;
      paddonrand=rand()%50;
      laddonrand=rand()%50;
      danrand=rand()%15;

      while (window.isOpen()){
        rotatec1=0;
        rotatec2=0;


        float time = clock.getElapsedTime().asSeconds(); 

        if(leveldis==0){
          /// for bullet time 
          bullettimer+= time;
          dbullettimer+=time;
          pbullettimer+=time;
          if(shieldc==1)
          shield+=time;
          
          monstertimer+=time;
          dragontimer+=time;
          if(monstertimer<monsterrand && dragontimer<dragonrand){
            paddontimer+=time;
            laddontimer+=time; 
            dantimer+=time;
          }
          //for the time of all enemy
          if(monstertimer<monsterrand && dragontimer<dragonrand)
            for(int i=0;i<alphan;i++)
              timerbt[i]+=time;
        }
        else
        levelctimer+=time;  
        ///this is bulid in for time recording
		outofLives(window);
        clock.restart();
        timer += time; 
  
    	  Event e;
        while (window.pollEvent(e)) {
          if (e.type == Event::Closed) // If cross/close is clicked/pressed
            window.close(); //close the game
        }    
      

        ////////////////////////This area is for display//////////////////////


        ////////this is for the display of the first meu
        windowoneandthreekeyevent(e,window, clockmove,timermove);
        if(enterc==1){
 
          windowtwokeyevents(e);
          
          ////these are rotate checker for its diffrent texture appearance

          if(rotatec1==1 && rotatec2==1){      
            p->rotatefun(1);
            rotatec=1;
            bulletrotate=-1;
            pbulletrotate=-1;
            }
          else if(rotatec1==2 && rotatec2==1){ 
            p->rotatefun(2);    
            rotatec=1;
            bulletrotate=1;
            pbulletrotate=1;
          }
          else if(rotatec1==0 && rotatec2==0 && rotatec==1){
            p->rotatefun(0);
            rotatec=0;
          }
          


          
          if(shieldc==1){
            if(shield>5){
              shield=0;
              shieldc=0;
            }
            pshield.setPosition(p->spritee().getPosition().x-18,p->spritee().getPosition().y-10);
          }
           
 
          if(monstertimer<monsterrand && dragontimer<dragonrand){    
            addonfun();
          } 
          if(monstertimer<monsterrand && dragontimer<dragonrand){
            levelfun(); 
            destroyEnemy();
            dropBomb(); 
            if(shieldc==0)
            collideEnemyDestroyAndBullet();  
            wrapScreen();
            if(fireaddonc==0)
            bulletMove();
            else{  
            powerupbulletmovefun(); 
            if(shieldc==0)
            destroyenemypowerup(); 
            }   
          }    

          if(monstertimer>monsterrand && dragonfirstc==0){
            if(shieldc==0)
            colidemonsterbeamandmonster(); 
            wrapScreen();
            bulletMove();            
          }   
          if(dragontimer>dragonrand && monsterfirstc==0){
            dragonmovefun(time);   
            if(shieldc==0)
                colidedragonbeamanddragon(); 
            wrapScreen();
            bulletMove();
          }

          window.clear(Color::Black); 
          window.draw(background); 
          fontdisplay(window);
          window.draw(p->spritee());
          if(fireaddonc==0 || monstertimer>monsterrand || dragontimer>dragonrand) 
            drawbullets(window);
          else
            drawpbullets(window);


          if(monstertimer>monsterrand && dragonfirstc==0)        
              monsterDisplay(window);
          if(monstertimer<monsterrand && dragontimer<dragonrand)
              enemydisplay(window); 
          if(dragontimer>dragonrand && monsterfirstc==0)
              dragondraw(window);
          if(monstertimer<monsterrand && dragontimer<dragonrand){
            window.draw(paddon);
            window.draw(addonlive->powerimg());
            window.draw(dan->powerimg());
          }

          if(shieldc==1)
            window.draw(pshield);
        }  

        firstanedthirdwindow(window);
        if(leveldis==1){
          levelfun();
          window.clear(Color::Black); 
          window.draw(background); 
          fontdisplay(window); 
          window.draw(level11);
        }         

        window.display();  
      }


    }
////////////////////////////////functions//////////////////////////////////////////////
void windowoneandthreekeyevent(sf::Event& e,sf::RenderWindow& window,Clock &clockmove,float &timermove){
    float time = clockmove.getElapsedTime().asSeconds();
    clockmove.restart();
    timermove += time;
    cout << timermove << endl;
    if(timermove>0.3)
        if(enterc==0){
            while(window.pollEvent(e))
          if(e.key.code == Keyboard::Down){
              if (a < 3)
                  if (a == 0)
                      a = 1;
                  else if (a == 1)
                      a = 2;
                  else if (a == 2)
                      a = 3;
              timermove = 0;
            
          }
          else if(e.key.code == Keyboard::Up){
              if (a > 0)

                  if (a == 1)
                      a = 0;
                  else if (a == 2)
                      a = 1;
                  else if (a == 3)
                      a = 2;
              timermove = 0;
 

          }        
          if(Keyboard::isKeyPressed(Keyboard::Enter)){
            if(a==0)
              enterc=1;
            if(a==1)
              inst=1;
            if(a==3)
              window.close();   
          }
          if(Keyboard::isKeyPressed(Keyboard::E)){
            if(inst==1)
              inst=0;               
          } 

        }
        /////this is for pause menu dispay
        if(enterc==2){

          if(e.key.code == Keyboard::Down){
            if(a<4)
            if(ac==0){
              a=a+1;
              ac=1;
            }  
            else if(ac==1){
              ac=0;
            }
          }
          if(e.key.code == Keyboard::Up){
            if(a>0)
            if(ac==0){
              a=a-1;
              ac=1;
            }  
            else if(ac==1){
              ac=0;
            }

          }        
          if(Keyboard::isKeyPressed(Keyboard::Enter)){
            
            if(a==0)
              enterc=1;
            if(a==2)
              inst=1;
            if(a==4)
              window.close();
            if(a==1)
              restartfun();
          }
          if(Keyboard::isKeyPressed(Keyboard::E)){
            if(inst==1)
              inst=0;

          }        
        }

 
}
void windowtwokeyevents(sf::Event& e){
                  
          if(Keyboard::isKeyPressed(Keyboard::E)){
              enterc=2;
              a=0;
          }      
          if (Keyboard::isKeyPressed(Keyboard::Left)){ 
            p->move("l");     
            rotatec1=1;
          }
          if (Keyboard::isKeyPressed(Keyboard::Right)){
            p->move("r");   
            rotatec1=2; 
                
          }
          if (Keyboard::isKeyPressed(Keyboard::Up)){  
            p->move("u");    
            rotatec2=1;
          }   
          if (Keyboard::isKeyPressed(Keyboard::Down)){  
            p->move("d"); 
          }  
}
void firstanedthirdwindow(sf::RenderWindow& window){
        if(a==0 && enterc==0){
            window.draw(m->pic());
            window.draw(font0);
        
        } 
        if(a==1 && enterc==0){
            window.draw(m->pic());
            if(inst==0)
            window.draw(font1);
              if(inst==1)
            window.draw(instruction);
        }  
        if(a==2 && enterc==0){
            window.draw(m->pic());
            window.draw(font2);
        }  
        if(a==3 && enterc==0){
            window.draw(m->pic());
            window.draw(font3);
          
        }   

        if(a==0 && enterc==2){
            window.draw(m->pic());
            window.draw(font20);
        } 
        if(a==1 && enterc==2){
            window.draw(m->pic());
            window.draw(font21);
        }  
        if(a==2 && enterc==2){
            window.draw(m->pic());
            if(inst==0)
            window.draw(font22);
              if(inst==1)
            window.draw(instruction);   
        }  
        if(a==3 && enterc==2){
            window.draw(m->pic());
            window.draw(font23); 
        } 
        if(a==4 && enterc==2){
            window.draw(m->pic());
            window.draw(font24);
        }
        
}
void restartfun(){
        for (int i = 0; i < 20; i++) {
          bullets[i]->bspritee().setPosition(-1000,-1000);
        }  
        score=0;
        lives=3;
        enterc=1;  
        lcheck=0;
        nextlevel=0;
}
void fontdisplay(RenderWindow& window){
          text.setFont(font);
          text.setString("Score");            
          text.setPosition(10,20);            
          text.setCharacterSize(40);  
          text.setFillColor(Color::White);
          text.setStyle(Text::Bold | Text::Underlined);
           
          Text dis_score(std::to_string (score), font);
          dis_score.setPosition(10,70);
          dis_score.setCharacterSize(60);
          dis_score.setFillColor(Color::White); 
          window.draw(dis_score);
          window.draw(text);



          text.setFont(fontl);
          text.setString("Lives");            
          text.setPosition(10,140);            
          text.setCharacterSize(40);  
          text.setFillColor(Color::White);
          text.setStyle(Text::Bold | Text::Underlined);
           
          Text plives(std::to_string (lives), font);
          plives.setPosition(10,190);
          plives.setCharacterSize(60);
          plives.setFillColor(Color::White); 
          window.draw(plives);
          window.draw(text);      
}
void drawbullets(sf::RenderWindow& window){
        for(int i=0;i<20;i++) 
          window.draw(bullets[i]->bspritee());
}
void drawpbullets(sf::RenderWindow& window){
        for(int i=0;i<20;i++)  
          window.draw(powerbullets[i]->powerimg());   
}
void dragondraw(sf::RenderWindow& window){
 
          for(int i=0;i<100;i++)  
            window.draw(dragonfire1[i]->bsprite);
          window.draw(en[4][0].eneimg());    
}
void monsterDisplay(sf::RenderWindow& window){
        if(monsterfirstc==0){
               en[3][0].eneimg().setPosition(220,10);////set a checker to see its correction
               monsterfirstc=1;
            }
          /////this is for the movement of the monster
          if( en[3][0].eneimg().getPosition().x<601 && en[3][0].eneimg().getPosition().x>-151 &&  Monstermc==0)
            en[3][0].eneimg().move(0.09,0);
          if( en[3][0].eneimg().getPosition().x<601 && en[3][0].eneimg().getPosition().x>-151 &&  Monstermc==1)
            en[3][0].eneimg().move(-0.09,0);
          if(en[3][0].eneimg().getPosition().x>=600)  
                Monstermc=1;
          if(en[3][0].eneimg().getPosition().x<=-150)
                Monstermc=0;

          mbeam.setPosition(en[3][0].eneimg().getPosition().x+172,en[3][0].eneimg().getPosition().y+250);
 
          window.draw(mbeam);
          window.draw(en[3][0].eneimg());
if(monstertimer>monsterrand+10){
  monsterfirstc=0;
  monstertimer=0;
  dragontimer=0;
  monsterrand=rand()%10+10;
  dragonrand=rand()%10+10;  
}
   
//          window.draw(sidedisplay);      
}
void enemydisplay(sf::RenderWindow& window){
 

         ////draw of alpha      
          for(int i=0;i<alphan;i++)
            window.draw(en[0][i].eneimg());   

          ////draw of beta
          for(int i=0;i<betan;i++)
            window.draw(en[1][i].eneimg());

          ////draw of gamma
          for(int i=0;i<gamman;i++)
            window.draw(en[2][i].eneimg());  

          /////Displying all the sprites
          //window.draw(sidedisplay);

          /////for display of the bomb
          for(int i=0;i<200;i++)
            window.draw(bomba[i]->spritee());  
}
void bulletMove(){
          /////////tis is for generation of the bullet 
          if(bullettimer>bulletInterval){
            if(bcheck2<20){
              bullets[bcheck2]->bspritee().setPosition(p->spritee().getPosition().x+15, p->spritee().getPosition().y-35); 
              bcheck2++;
              if(bulletrotate==-1){
                bulletrotatecl++;
                bulletrotatearrayl[bulletrotatecl-1]=bcheck2-1;  
                bullets[bcheck2-1]->bspritee().setPosition(p->spritee().getPosition().x-20, p->spritee().getPosition().y-25);
                bulletrotate=0;
              } 
              if(bulletrotate==1){
                bulletrotatecr++;
                bulletrotatearrayr[bulletrotatecr-1]=bcheck2-1;  
                bullets[bcheck2-1]->bspritee().setPosition(p->spritee().getPosition().x+20, p->spritee().getPosition().y+15);
                bulletrotate=0;
              } 
  
              if(bcheck2==20){   
                bcheck2=0;
                bulletrotatecl=0;
                bulletrotatecr=0;
                for(int i=0;i<20;i++)
                  bullets[i]->bspritee().setTexture(bullets[i]->btexe());
                
                }
              }       
            bullettimer=0;	
          }
          ///////this is for display of bullet
          for(int i=0;i<20;i++)  
            p->pbullet(bullets[i]);

          for(int i=0;i<bulletrotatecl;i++){
            p->rotatemoveL(bullets[bulletrotatearrayl[i]]);
            bullets[bulletrotatearrayl[i]]->bspritee().setTexture(bulletlrt);
             
          }  
          for(int i=0;i<bulletrotatecr;i++){
            p->rotatemoveR(bullets[bulletrotatearrayr[i]]);
            bullets[bulletrotatearrayr[i]]->bspritee().setTexture(bulletrrt);
             
          }

}
void dragonmovefun(float& time){
if(dragonfirstc==0)
  dragonfirstc=1;  
if(dbullettimer>dbulletinterval){
            if(dbcheck2<100){
              dragonfire1[dbcheck2]->bsprite.setPosition(320,280); 
              dbcheck2++;
 
 // cout<<time<<endl;
              if(dbcheck2==100)  
                dbcheck2=0;
     
            dbullettimer=0;	
          }

}  
          ///////this is for display of bullet
if(dcheck==0){
  if(  p->spritee().getPosition().x<230)
    dragonp=-1;
  if(  p->spritee().getPosition().x<530 && p->spritee().getPosition().x>230)
    dragonp=0;
  if(  p->spritee().getPosition().x>=530 && p->spritee().getPosition().x<900)      
     dragonp=2.5;   
  dcheck=1;   
}     
          for(int i=0;i<100;i++){  
            dragonfire1[i]->bsprite.move(dragonp,2);
      //      cout<<(p->sprite.getPosition().x)<<endl;
      //      cout<<(dragonfire1[i]->bsprite.getPosition().x)<<endl;
          }    
if(dragontimer>dragonrand+5){
  dragonfirstc=0;
  monstertimer=0;
  dragontimer=0;
  monsterrand=rand()%10+10;
  dragonrand=rand()%10+10;
  dcheck=0;
}          
}
void destroyEnemy(){

          /////////this is to destroy enemy and work for power up 
          /////this is for destroying alpha
          for (int i = 0; i < alphan; i++) {
              for (int j = 0; j < 20; j++) {
                sf::FloatRect rect1 = bullets[j]->bspritee().getGlobalBounds(); 
                sf::FloatRect rect2 = en[0][i].eneimg().getGlobalBounds();         
                if ((rect1.left < rect2.left + rect2.width) && (rect1.left + rect1.width > rect2.left) && (rect1.top < rect2.top + rect2.height) && (rect1.top + rect1.height > rect2.top)) {
                  bullets[j]->bspritee().setPosition(-1000,-1000);           
                  en[0][i].eneimg().setPosition(2000,1000);
                  bullet_hit_enemy = true;
                 
                  score+=10;
                  break;
                }
              }
            }
          //////this is for destroying the beta  
          for (int i = 0; i < betan; i++) {
            for (int j = 0; j < 20; j++) {
              sf::FloatRect rect1 = bullets[j]->bspritee().getGlobalBounds(); 
              sf::FloatRect rect2 = en[1][i].eneimg().getGlobalBounds();         
              if ((rect1.left < rect2.left + rect2.width) && (rect1.left + rect1.width > rect2.left) && (rect1.top < rect2.top + rect2.height) && (rect1.top + rect1.height > rect2.top)) {
                bullets[j]->bspritee().setPosition(-1000,-1000);
                en[1][i].eneimg().setPosition(2000,1000);
                bullet_hit_enemy = true;
                score+=20;
                
                break;
              }
            }
          }
          //////this is for the destruction of the gamma
          for (int i = 0; i < gamman; i++) {
            for (int j = 0; j < 20; j++) {
              sf::FloatRect rect1 = bullets[j]->bspritee().getGlobalBounds(); 
              sf::FloatRect rect2 = en[2][i].eneimg().getGlobalBounds();         
              if ((rect1.left < rect2.left + rect2.width) && (rect1.left + rect1.width > rect2.left) && (rect1.top < rect2.top + rect2.height) && (rect1.top + rect1.height > rect2.top)) {
                bullets[j]->bspritee().setPosition(-1000,-1000);
                en[2][i].eneimg().setPosition(2000,1000);
                bullet_hit_enemy = true;
                score+=30;
                
                break;
              }
            }
          }
  
}
void powerupbulletmovefun(){
          
          if(pbullettimer>pbulletinterval){
            if(pbcheck2<20){
              powerbullets[pbcheck2]->powerimg().setPosition(p->spritee().getPosition().x+15, p->spritee().getPosition().y-35); 
              pbcheck2++;
              if(pbulletrotate==-1){
                pbulletrotatecl++;
                pbulletrotatearrayl[pbulletrotatecl-1]=pbcheck2-1;  
                powerbullets[pbcheck2-1]->powerimg().setPosition(p->spritee().getPosition().x-18, p->spritee().getPosition().y-25);
                pbulletrotate=0;
              } 
              if(pbulletrotate==1){
                pbulletrotatecr++;
                pbulletrotatearrayr[pbulletrotatecr-1]=pbcheck2-1;  
                powerbullets[pbcheck2-1]->powerimg().setPosition(p->spritee().getPosition().x+30, p->spritee().getPosition().y);
                pbulletrotate=0;
              } 
  
              if(pbcheck2==20){   
                pbcheck2=0;
                pbulletrotatecl=0;
                pbulletrotatecr=0;
                for(int i=0;i<20;i++)
                  powerbullets[i]->powerimg().setTexture(powerbullets[i]->powertext());
                
                }
              }       
            pbullettimer=0;	
          }         

          ///////////this is for move of firebullet

          for(int i=0;i<20;i++)  
            p->powerbullet(powerbullets[i]);

          for(int i=0;i<pbulletrotatecl;i++){
            p->protatemoveL(powerbullets[pbulletrotatearrayl[i]]);
            powerbullets[pbulletrotatearrayl[i]]->powerimg().setTexture(pbulletlrt);
             
          }  
          for(int i=0;i<pbulletrotatecr;i++){
            p->protatemoveR(powerbullets[pbulletrotatearrayr[i]]);
            powerbullets[pbulletrotatearrayr[i]]->powerimg().setTexture(pbulletrrt);
             
          }

}
void destroyenemypowerup(){

          for (int i = 0; i < alphan; i++) {
              for (int j = 0; j < 20; j++) {
                sf::FloatRect rect1 = powerbullets[j]->powerimg().getGlobalBounds(); 
                sf::FloatRect rect2 = en[0][i].eneimg().getGlobalBounds();         
                if ((rect1.left < rect2.left + rect2.width) && (rect1.left + rect1.width > rect2.left) && (rect1.top < rect2.top + rect2.height) && (rect1.top + rect1.height > rect2.top)) {
        //          bullets[j]->bsprite.setPosition(100,-500);           
                  en[0][i].eneimg().setPosition(2000,1000);
                  bullet_hit_enemy = true;
                  score+=10;
                   
                  break;
                }
              }
            }
          //////this is for destroying the beta  
          for (int i = 0; i < betan; i++) {
            for (int j = 0; j < 20; j++) {
              sf::FloatRect rect1 = powerbullets[j]->powerimg().getGlobalBounds(); 
              sf::FloatRect rect2 = en[1][i].eneimg().getGlobalBounds();         
              if ((rect1.left < rect2.left + rect2.width) && (rect1.left + rect1.width > rect2.left) && (rect1.top < rect2.top + rect2.height) && (rect1.top + rect1.height > rect2.top)) {
   //             bullets[j]->bsprite.setPosition(100,-500);
                en[1][i].eneimg().setPosition(2000,1000);
                score+=20;
                                
                bullet_hit_enemy = true;
                break;
              }
            }
          }
          //////this is for the destruction of the gamma
          for (int i = 0; i < gamman; i++) {
            for (int j = 0; j < 20; j++) {
              sf::FloatRect rect1 = powerbullets[j]->powerimg().getGlobalBounds(); 
              sf::FloatRect rect2 = en[2][i].eneimg().getGlobalBounds();         
              if ((rect1.left < rect2.left + rect2.width) && (rect1.left + rect1.width > rect2.left) && (rect1.top < rect2.top + rect2.height) && (rect1.top + rect1.height > rect2.top)) {
   //             bullets[j]->bsprite.setPosition(100,-500);
                en[2][i].eneimg().setPosition(2000,1000);
                bullet_hit_enemy = true;
                score+=30;
                                
                break;
              }
            }
          }  
          if(paddontimer>paddonrand+5){
            fireaddonc=0;
            paddontimer=rand()%50;
            paddoncfirst=0;
          }
  
}
void colidemonsterbeamandmonster(){
          sf::FloatRect rect1 = p->spritee().getGlobalBounds(); 
          sf::FloatRect rect2 = mbeam.getGlobalBounds();         
          if ((rect1.left < rect2.left + rect2.width) && (rect1.left + rect1.width > rect2.left) && (rect1.top < rect2.top + rect2.height) && (rect1.top + rect1.height > rect2.top)) {
            lives--;
            p->spritee().setPosition(340,622);  
            shieldc=1;         
          }
          if(shieldc==0){
          sf::FloatRect rect3 = p->spritee().getGlobalBounds(); 
          sf::FloatRect rect4 = en[3][0].eneimg().getGlobalBounds();         
          if ((rect3.left < rect4.left + rect4.width) && (rect3.left + rect3.width > rect4.left) && (rect3.top < rect4.top + rect4.height) && (rect3.top + rect3.height > rect4.top)) {
            lives--;
            p->spritee().setPosition(340,622);   
             shieldc=1;        
          }
          }




}
void colidedragonbeamanddragon(){
          for(int i=0;i<100;i++){
            sf::FloatRect rect1 = p->spritee().getGlobalBounds(); 
            sf::FloatRect rect2 = dragonfire1[i]->bsprite.getGlobalBounds();         
            if ((rect1.left < rect2.left + rect2.width) && (rect1.left + rect1.width > rect2.left) && (rect1.top < rect2.top + rect2.height) && (rect1.top + rect1.height > rect2.top)) {
              lives--;
			 
              //outofLives();
               shieldc=1;
              p->spritee().setPosition(340,622);           
            }
          }
          if( shieldc==0){
          sf::FloatRect rect3 = p->spritee().getGlobalBounds(); 
          sf::FloatRect rect4 = en[4][0].eneimg().getGlobalBounds();         
          if ((rect3.left < rect4.left + rect4.width) && (rect3.left + rect3.width > rect4.left) && (rect3.top < rect4.top + rect4.height) && (rect3.top + rect3.height > rect4.top)) {
            lives--;
           // outofLives();
             shieldc=1;
            p->spritee().setPosition(340,622);           
          }
          }




}
void collideEnemyDestroyAndBullet(){
          for(int i=0;i<3;i++)
            for(int j=0;j<30;j++){
              FloatRect rect1 = p->spritee().getGlobalBounds(); 
              FloatRect rect2 = en[i][j].eneimg().getGlobalBounds();         
              if ((rect1.left < rect2.left + rect2.width) && (rect1.left + rect1.width > rect2.left) && (rect1.top < rect2.top + rect2.height) && (rect1.top + rect1.height > rect2.top)) { 
                lives--;
                //outofLives();
                 shieldc=1;
                p->spritee().setPosition(340,622); 
                break;
            }
          }
          if( shieldc==0){
          for(int i=0;i<200;i++){
              sf::FloatRect rect1 = p->spritee().getGlobalBounds(); 
              sf::FloatRect rect2 = bomba[i]->spritee().getGlobalBounds();         
              if ((rect1.left < rect2.left + rect2.width) && (rect1.left + rect1.width > rect2.left) && (rect1.top < rect2.top + rect2.height) && (rect1.top + rect1.height > rect2.top)) { 
                lives--;
                //outofLives();
                p->spritee().setPosition(340,622); 
                 shieldc=1;
                break;
              }
            }  
          } 
}
void wrapScreen(){
          if(p->spritee().getPosition().x<-75)
            p->spritee().setPosition(845,p->spritee().getPosition().y);
          if(p->spritee().getPosition().x>845)
            p->spritee().setPosition(-75,p->spritee().getPosition().y);
          if(p->spritee().getPosition().y<-80)
            p->spritee().setPosition(p->spritee().getPosition().x,710);
          if(p->spritee().getPosition().y>710)
            p->spritee().setPosition(p->spritee().getPosition().x,-80);  
 
}
void dropBomb(){

          ///////this code is for the the drop of bomb
          for(int i=0;i<bombloopcount;i++){
            if(erand[i]==0){
              if(timerbt[i]>5){
                bdcount++;
                bomba[bdcount]->spritee().setPosition(en[erand[i]][i+1].eneimg().getPosition().x,en[erand[i]][i+1].eneimg().getPosition().y+33);   
                if(bdcount>=198){
                  bdcount=0;
                  for(int i=0;i<100;i++){
                    bomba[i]->spritee().setPosition(1000,1000);
                  }                
                } 
                  if(bdcount==100){
                  for(int i=100;i<198;i++){
                    bomba[i]->spritee().setPosition(1000,1000);                  
                  }
              }   
              timerbt[i]=0;   
              }
            }  
            if(erand[i]==1){
              if(timerbt[i]>3){
                bdcount++;
                bomba[bdcount]->spritee().setPosition(en[erand[i]][i+1].eneimg().getPosition().x,en[erand[i]][i+1].eneimg().getPosition().y+33);    
                
                if(bdcount>=198){
                  bdcount=0;
                  for(int i=0;i<100;i++){
                    bomba[i]->spritee().setPosition(1000,1000);
                  }                
                } 
                  if(bdcount==100){
                  for(int i=100;i<198;i++){
                    bomba[i]->spritee().setPosition(1000,1000);                  
                  }
              } 
              timerbt[i]=0; 
            } 
            }
            if(erand[i]==2){
              if(timerbt[i]>2){  
                bdcount++;         
                bomba[bdcount]->spritee().setPosition(en[erand[i]][i+1].eneimg().getPosition().x,en[erand[i]][i+1].eneimg().getPosition().y+33);              
                timerbt[i]=0;
                if(bdcount>=198){
                  bdcount=0;
                  for(int i=0;i<100;i++){
                    bomba[i]->spritee().setPosition(1000,1000);
                  }                
                } 
                  if(bdcount==100){
                  for(int i=100;i<198;i++){
                    bomba[i]->spritee().setPosition(1000,1000);                  
                  }
              } 
              timerbt[i]=0;  
              }
            }
          }  
          ////this code is for the move of bomb
          for(int i=0;i<200;i++)
            en[erand[0]][0].bombmove(bomba[i]);


}
void levelfun(){
          if(lcheck==0 && nextlevel==0){
            ////this is for the set of all enemy to a default position
            for(int i=0;i<3;i++)
              for(int j=0;j<30;j++){
                en[i][j].eneimg().setPosition(2000,1000); 
            }    
            ////this for random set of the enemy 
          for(int i=0;i<alphan;i++){
              erand[i]=rand()%3;
            }
            /////this is for the random set of the timer of each random enemy
          for(int i=0;i<alphan;i++)
              timerbt[i]+=(rand()%99)*0.01;

              ////this code is for the set of the enemy  
            en[erand[0]][1].eneimg().setPosition(90,20); 
            en[erand[1]][2].eneimg().setPosition(165,20);
            en[erand[2]][3].eneimg().setPosition(240,20);
            en[erand[3]][4].eneimg().setPosition(315,20);
            en[erand[4]][5].eneimg().setPosition(390,20);
            en[erand[5]][6].eneimg().setPosition(465,20);
            en[erand[6]][7].eneimg().setPosition(540,20); 
            en[erand[7]][8].eneimg().setPosition(615,20);
            en[erand[8]][9].eneimg().setPosition(690,20);
            en[erand[9]][10].eneimg().setPosition(90,100); 
            en[erand[10]][11].eneimg().setPosition(90,200); 
            en[erand[11]][12].eneimg().setPosition(90,300); 
            en[erand[12]][13].eneimg().setPosition(165,300);
            en[erand[13]][14].eneimg().setPosition(240,300);
            en[erand[14]][15].eneimg().setPosition(315,300);
            en[erand[15]][16].eneimg().setPosition(390,300);
            en[erand[16]][17].eneimg().setPosition(465,300);
            en[erand[17]][18].eneimg().setPosition(540,300); 
            en[erand[18]][19].eneimg().setPosition(615,300);
            en[erand[19]][20].eneimg().setPosition(690,300);
            en[erand[20]][21].eneimg().setPosition(690,100); 
            en[erand[21]][22].eneimg().setPosition(690,200);
            bombloopcount=22;
            nextlevel++;
            lcheck=1;
          }
          if(levelgc==0)
            if(nextlevel==1){
              leveldis=1;
              enterc=4;
              if(levelctimer>2){
              leveldis=0;
              enterc=1;
              levelgc=1;
              levelctimer=0;
              }
              
          }
          for(int i=0;i<3;i++)
            for(int j=0;j<30;j++)
              if(en[i][j].eneimg().getPosition().x==2000)
                nextlevelcount++; 
  //        cout<<nextlevelcount<<endl;              
          if(nextlevelcount==90)
            nextlevel++;
          else
            nextlevelcount=0;    


          ////this is the first level of the game         
          if(nextlevel==2){
            ////this is for the set of all enemy to a default position 
            for(int i=0;i<3;i++)
              for(int j=0;j<30;j++){
                en[i][j].eneimg().setPosition(2000,1000); 
            } 
            ////this for random set of the enemy    
            for(int i=0;i<alphan;i++){
              erand[i]=rand()%3;
            }  
            ///this code is for the set of the
            en[erand[0]][1].eneimg().setPosition(90,260); 
            en[erand[1]][2].eneimg().setPosition(165,200);
            en[erand[2]][3].eneimg().setPosition(240,140);
            en[erand[3]][4].eneimg().setPosition(315,80);
            en[erand[4]][5].eneimg().setPosition(390,20);
            en[erand[5]][6].eneimg().setPosition(465,80);
            en[erand[6]][7].eneimg().setPosition(540,140); 
            en[erand[7]][8].eneimg().setPosition(615,200);
            en[erand[8]][9].eneimg().setPosition(690,260);
            en[erand[9]][10].eneimg().setPosition(165,260);
            en[erand[10]][11].eneimg().setPosition(240,260);
            en[erand[11]][12].eneimg().setPosition(315,260);
            en[erand[12]][13].eneimg().setPosition(390,260);
            en[erand[13]][14].eneimg().setPosition(465,260);
            en[erand[14]][15].eneimg().setPosition(540,260); 
            en[erand[15]][16].eneimg().setPosition(615,260);
            nextlevel++;
            bombloopcount=16;
          }
          if(nextlevel==4){
            ////this is for the set of all enemy to a default position
            for(int i=0;i<3;i++)
              for(int j=0;j<30;j++){
                en[i][j].eneimg().setPosition(2000,1000); 
            }
            ////this for random set of the enemy    
            for(int i=0;i<alphan;i++){
                erand[i]=rand()%3;
              }
              ///this code is for the set of the  
            en[erand[0]][1].eneimg().setPosition(90,20); 
            en[erand[1]][2].eneimg().setPosition(165,70);
            en[erand[2]][3].eneimg().setPosition(240,130);
            en[erand[3]][4].eneimg().setPosition(315,180);
            en[erand[4]][5].eneimg().setPosition(390,240);
            en[erand[5]][6].eneimg().setPosition(465,290);
            en[erand[6]][7].eneimg().setPosition(540,340); 
            en[erand[7]][8].eneimg().setPosition(615,390);
            en[erand[8]][9].eneimg().setPosition(690,440);
            en[erand[9]][10].eneimg().setPosition(690,20); 
            en[erand[10]][11].eneimg().setPosition(615,70);
            en[erand[11]][12].eneimg().setPosition(540,130);
            en[erand[12]][13].eneimg().setPosition(465,180);

            en[erand[13]][14].eneimg().setPosition(315,290);
            en[erand[14]][15].eneimg().setPosition(240,340); 
            en[erand[15]][16].eneimg().setPosition(165,390);
            en[erand[16]][17].eneimg().setPosition(90,440);
            nextlevel++;
            bombloopcount=17;
          }
          if(nextlevel==6){
            ////this is for the set of all enemy to a default position
            for(int i=0;i<3;i++)
              for(int j=0;j<30;j++){
                en[i][j].eneimg().setPosition(2000,1000); 
            } 
            ////this for random set of the enemy
            for(int i=0;i<alphan;i++){
              erand[i]=rand()%3;
            }  
            ///this code is for the set of the           
            en[erand[0]][1].eneimg().setPosition(90,240); 
            en[erand[1]][2].eneimg().setPosition(165,180);
            en[erand[2]][3].eneimg().setPosition(240,130);
            en[erand[3]][4].eneimg().setPosition(315,70);
            en[erand[4]][5].eneimg().setPosition(390,20);
            en[erand[5]][6].eneimg().setPosition(465,70);
            en[erand[6]][7].eneimg().setPosition(540,130); 
            en[erand[7]][8].eneimg().setPosition(615,180);
            en[erand[8]][9].eneimg().setPosition(690,240);

            en[erand[9]][11].eneimg().setPosition(165,290);
            en[erand[10]][12].eneimg().setPosition(240,340);
            en[erand[11]][13].eneimg().setPosition(315,390);
            en[erand[12]][14].eneimg().setPosition(390,440);
            en[erand[13]][15].eneimg().setPosition(465,390); 
            en[erand[14]][16].eneimg().setPosition(540,340);
            en[erand[15]][17].eneimg().setPosition(615,290);
            bombloopcount=17;
            nextlevel++;
 
          }
          if(nextlevel==8){
            ////this is for the set of all enemy to a default position
            for(int i=0;i<3;i++)
              for(int j=0;j<30;j++){
                en[i][j].eneimg().setPosition(2000,1000); 
            }  
            ////this for random set of the enemy
            for(int i=0;i<alphan;i++){
              erand[i]=rand()%3;
            } 
            ///this code is for the set of the           
            en[erand[0]][1].eneimg().setPosition(90,260); 
            en[erand[1]][2].eneimg().setPosition(135,180);
            en[erand[2]][3].eneimg().setPosition(200,110);
            en[erand[3]][4].eneimg().setPosition(285,60);
            en[erand[4]][5].eneimg().setPosition(390,20);
            en[erand[5]][6].eneimg().setPosition(495,60);
            en[erand[6]][7].eneimg().setPosition(580,110); 
            en[erand[7]][8].eneimg().setPosition(645,180);
            en[erand[8]][9].eneimg().setPosition(690,260);

            en[erand[9]][11].eneimg().setPosition(135,340);
            en[erand[12]][12].eneimg().setPosition(200,410);
            en[erand[13]][13].eneimg().setPosition(285,450);
            en[erand[14]][14].eneimg().setPosition(390,500);
            en[erand[15]][15].eneimg().setPosition(495,450); 
            en[erand[16]][16].eneimg().setPosition(580,410);
            en[erand[17]][17].eneimg().setPosition(645,340);
            nextlevel++;
            bombloopcount=17;
 
          }
          if(nextlevel==10){
            ////this is for the set of all enemy to a default position
            for(int i=0;i<3;i++)
              for(int j=0;j<30;j++){
                en[i][j].eneimg().setPosition(2000,1000); 
            } 
            ////this for random set of the enemy
            for(int i=0;i<alphan;i++){
              erand[i]=rand()%3;
            }  
            ///this code is for the set of the         
            en[erand[0]][1].eneimg().setPosition(90,180); 
            en[erand[1]][2].eneimg().setPosition(135,100);
            en[erand[2]][3].eneimg().setPosition(200,30);
            en[erand[3]][4].eneimg().setPosition(285,100);
            en[erand[4]][5].eneimg().setPosition(390,180);
            en[erand[5]][6].eneimg().setPosition(495,100);
            en[erand[6]][7].eneimg().setPosition(580,30); 
            en[erand[7]][8].eneimg().setPosition(645,100);
            en[erand[8]][9].eneimg().setPosition(690,180);

            en[erand[9]][11].eneimg().setPosition(135,260);
            en[erand[11]][12].eneimg().setPosition(200,330);
            en[erand[12]][13].eneimg().setPosition(285,370);
            en[erand[13]][14].eneimg().setPosition(390,420);
            en[erand[14]][15].eneimg().setPosition(495,370); 
            en[erand[15]][16].eneimg().setPosition(580,330);
            en[erand[16]][17].eneimg().setPosition(645,260);
            bombloopcount=17;
            nextlevel++;
          }
          if(nextlevel==12){
            ////this is for the set of all enemy to a default position
            for(int i=0;i<3;i++)
              for(int j=0;j<30;j++){
                en[i][j].eneimg().setPosition(2000,1000); 
            } 
            ////this for random set of the enemy
            for(int i=0;i<alphan;i++){
              erand[i]=rand()%3;
            }  
            ///this code is for the set of the         
            en[erand[0]][1].eneimg().setPosition(90,180); 
            en[erand[1]][2].eneimg().setPosition(135,100);
            en[erand[2]][3].eneimg().setPosition(200,30);
            en[erand[3]][4].eneimg().setPosition(285,100);
            en[erand[4]][5].eneimg().setPosition(390,180);
            en[erand[5]][6].eneimg().setPosition(495,100);
            en[erand[6]][7].eneimg().setPosition(580,30); 
            en[erand[7]][8].eneimg().setPosition(645,100);
            en[erand[8]][9].eneimg().setPosition(690,180);

            en[erand[9]][11].eneimg().setPosition(135,260);
            en[erand[11]][12].eneimg().setPosition(200,330);
            en[erand[12]][13].eneimg().setPosition(285,370);
            en[erand[13]][14].eneimg().setPosition(390,420);
            en[erand[14]][15].eneimg().setPosition(495,370); 
            en[erand[15]][16].eneimg().setPosition(580,330);
            en[erand[16]][17].eneimg().setPosition(645,260);

            en[erand[17]][18].eneimg().setPosition(205,180);
            en[erand[18]][19].eneimg().setPosition(290,260);
            en[erand[19]][20].eneimg().setPosition(390,300); 
            en[erand[20]][21].eneimg().setPosition(570,180);
            en[erand[21]][22].eneimg().setPosition(500,260);
            bombloopcount=22;
            nextlevel++;
          } 
             

          if(nextlevel==14){
            ////this is for the set of all enemy to a default position 
            for(int i=0;i<3;i++)
              for(int j=0;j<30;j++){
                en[i][j].eneimg().setPosition(2000,1000); 
            } 
            ////this for random set of the enemy    
            for(int i=0;i<alphan;i++){
              erand[i]=rand()%3;
            }  
            ///this code is for the set of the
            en[erand[0]][1].eneimg().setPosition(90,260); 
            en[erand[1]][2].eneimg().setPosition(165,200);
            en[erand[2]][3].eneimg().setPosition(240,140);
            en[erand[3]][4].eneimg().setPosition(315,80);
            en[erand[4]][5].eneimg().setPosition(390,20);
            en[erand[5]][6].eneimg().setPosition(465,80);
            en[erand[6]][7].eneimg().setPosition(540,140); 
            en[erand[7]][8].eneimg().setPosition(615,200);
            en[erand[8]][9].eneimg().setPosition(690,260);
            en[erand[9]][10].eneimg().setPosition(165,260);
            en[erand[10]][11].eneimg().setPosition(240,260);
            en[erand[11]][12].eneimg().setPosition(315,260);
            en[erand[12]][13].eneimg().setPosition(390,260);
            en[erand[13]][14].eneimg().setPosition(465,260);
            en[erand[14]][15].eneimg().setPosition(540,260); 
            en[erand[15]][16].eneimg().setPosition(615,260);

            en[erand[16]][17].eneimg().setPosition(360,140);
            en[erand[17]][18].eneimg().setPosition(440,140);
            en[erand[18]][19].eneimg().setPosition(290,200); 
            en[erand[19]][20].eneimg().setPosition(390,200);
            en[erand[20]][21].eneimg().setPosition(490,200);
            nextlevel++;
            bombloopcount=21;
          }         

          if(nextlevel==16){
            ////this is for the set of all enemy to a default position
            for(int i=0;i<3;i++)
              for(int j=0;j<30;j++){
                en[i][j].eneimg().setPosition(2000,1000); 
            } 
            ////this for random set of the enemy
            for(int i=0;i<alphan;i++){
              erand[i]=rand()%3;
            }  
            ///this code is for the set of the           
            en[erand[0]][1].eneimg().setPosition(90,240); 
            en[erand[1]][2].eneimg().setPosition(165,180);
            en[erand[2]][3].eneimg().setPosition(240,130);
            en[erand[3]][4].eneimg().setPosition(315,70);
            en[erand[4]][5].eneimg().setPosition(390,20);
            en[erand[5]][6].eneimg().setPosition(465,70);
            en[erand[6]][7].eneimg().setPosition(540,130); 
            en[erand[7]][8].eneimg().setPosition(615,180);
            en[erand[8]][9].eneimg().setPosition(690,240);

            en[erand[9]][11].eneimg().setPosition(165,290);
            en[erand[10]][12].eneimg().setPosition(240,340);
            en[erand[11]][13].eneimg().setPosition(315,390);
            en[erand[12]][14].eneimg().setPosition(390,440);
            en[erand[13]][15].eneimg().setPosition(465,390); 
            en[erand[14]][16].eneimg().setPosition(540,340);
            en[erand[15]][17].eneimg().setPosition(615,290);

            en[erand[16]][18].eneimg().setPosition(240,240);
            en[erand[18]][19].eneimg().setPosition(340,240);
            en[erand[19]][20].eneimg().setPosition(440,240);
            en[erand[20]][21].eneimg().setPosition(540,240);

            en[erand[21]][22].eneimg().setPosition(320,170); 
            en[erand[22]][23].eneimg().setPosition(470,170);
            en[erand[23]][24].eneimg().setPosition(390,120);
            en[erand[24]][25].eneimg().setPosition(320,300); 
            en[erand[25]][26].eneimg().setPosition(470,300);
            en[erand[26]][27].eneimg().setPosition(390,350);            

            bombloopcount=17;
            nextlevel++; 
          }



}
void addonfun(){
              if(paddontimer>paddonrand){
                if(paddoncfirst==0){
                  paddon.setPosition(rand()%780,0);
                  paddoncfirst=1;
                }
                paddon.move(0,0.2);
              }  

              {
              sf::FloatRect rect1 = paddon.getGlobalBounds(); 
              sf::FloatRect rect2 = p->spritee().getGlobalBounds();         
              if ((rect1.left < rect2.left + rect2.width) && (rect1.left + rect1.width > rect2.left) && (rect1.top < rect2.top + rect2.height) && (rect1.top + rect1.height > rect2.top)){
                paddon.setPosition(2000,-100);
                fireaddonc=1;
                paddontimer=paddonrand;
              } 
              }
              ////////////////////////
          //    cout<<laddontimer<<" "<<laddonrand<<endl;
              if(laddontimer>laddonrand){
                if(laddoncfirst==0){
                  addonlive->powerimg().setPosition(rand()%780,0);
                  laddoncfirst=1;
                }
                addonlive->powerimg().move(0,0.2);
              }  

            {
              FloatRect rect1 = addonlive->powerimg().getGlobalBounds(); 
              FloatRect rect2 = p->spritee().getGlobalBounds();         
              if ((rect1.left < rect2.left + rect2.width) && (rect1.left + rect1.width > rect2.left) && (rect1.top < rect2.top + rect2.height) && (rect1.top + rect1.height > rect2.top)){
                addonlive->powerimg().setPosition(2000,-100);
                lives++;
                laddoncfirst=0;
                laddontimer=0;
                laddonrand=rand()%50;
              } 
            }
           //////////////////////////////
              if(dantimer>danrand){
                if(daddoncfirst==0){
                  dan->powerimg().setPosition(rand()%780,0);
                  daddoncfirst=1;
                }
                dan->powerimg().move(0,0.2);
              }  
            if(shieldc==0)
            {
              FloatRect rect1 = dan->powerimg().getGlobalBounds(); 
              FloatRect rect2 = p->spritee().getGlobalBounds();         
              if ((rect1.left < rect2.left + rect2.width) && (rect1.left + rect1.width > rect2.left) && (rect1.top < rect2.top + rect2.height) && (rect1.top + rect1.height > rect2.top)){
                dan->powerimg().setPosition(2000,-100);
                p->spritee().setPosition(340,622);
                lives--;
                daddoncfirst=0;
                shieldc=1;
                dantimer=0;
                danrand=rand()%50;
              } 
            } 
}

    void outofLives(RenderWindow & window) {
        if (lives == 0 || lives < 0) {
			lives = 3;
			cout << "Game Over" << endl;
			score = 0;
           // start_game();
            gameOver(window);
        }
    }

    void gameOver(sf::RenderWindow& window) {
        // Prepare the "Game Over" message
        Text gameOverText;

        gameOverText.setFont(font);
        gameOverText.setString("Game Over\nPress R to Restart\nPress Q to Quit");
        gameOverText.setCharacterSize(50);
        gameOverText.setFillColor(Color::Red);
        gameOverText.setStyle(Text::Bold);
        gameOverText.setPosition(100, 200);

        // Clear any remaining events
        Event event;

        // Display the "Game Over" screen
        while (window.isOpen()) {
            while (window.pollEvent(event)) {
                if (event.type == Event::Closed) {
                    window.close();
                    return;
                }

                // Handle restart or quit
                if (Keyboard::isKeyPressed(Keyboard::R)) {
                    restartfun(); // Restart the game
                    return;
                }
                else if (Keyboard::isKeyPressed(Keyboard::Q)) {
                    window.close(); // Quit the game
                    return;
                }
            }

            // Render the "Game Over" screen
            window.clear(Color::Black);
            window.draw(background);
            window.draw(gameOverText);
            window.display();
        }
    }


};
