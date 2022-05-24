#include<stdlib.h>
#include<stdio.h>
#include<math.h>
#include<SDL/SDL.h>
#include<SDL_image.h>
#include<SDL/SDL_ttf.h>
#define largeur 1344
#define hauteur 672
float fonctioon(float x);
float fonctioon(float x)
{
  float result;
  result=exp(x);
  return result;
}
int main(int argc,char *argv[] )
{  int i,rem=0,aide=0,aide2=0,aideu=0,recaly,aide2u=0,recald,aidefonctionu=0,aidefonction=0,le=0,up=0,o=28,ff=2,d=4,gr=1;
	float Pa,f;
	int A,B;
	SDL_Init(SDL_INIT_VIDEO);
	TTF_Init();
	SDL_Surface *screen=NULL,*back=NULL,*fonction=NULL,*gG=NULL,*dD=NULL,*gradeh=NULL,*gradev=NULL;
	SDL_Rect posfonction,posdD,posgG,posgradeh,posgradev,posback;
    screen=SDL_SetVideoMode(largeur,hauteur,32,SDL_HWSURFACE | SDL_DOUBLEBUF);
    //back
    back=SDL_CreateRGBSurface(SDL_HWSURFACE,largeur,hauteur,32,0,0,0,0);
    posback.x=0;
    posback.y=0;
    SDL_BlitSurface(back,NULL,screen,&posback);
    //dD
    dD=SDL_CreateRGBSurface(SDL_HWSURFACE,d,hauteur,32,0,0,0,0);
     SDL_FillRect(dD,NULL,SDL_MapRGB(dD->format,255,0,0));
     posdD.x=screen->w/2-dD->w/2;
    recald=screen->w/2-dD->w/2;
    posdD.y=screen->h/2-dD->h/2;
    //gG
     gG=SDL_CreateRGBSurface(SDL_HWSURFACE,largeur,d,32,0,0,0,0);
     SDL_FillRect(gG,NULL,SDL_MapRGB(gG->format,255,0,0));
    posgG.x=screen->w/2-gG->w/2;
    posgG.y=screen->h/2-gG->h/2;
    recaly=screen->h/2-gG->h/2;
     //focntion
    fonction=SDL_CreateRGBSurface(SDL_HWSURFACE,ff,ff,32,0,0,0,0);
    SDL_FillRect(fonction,NULL,SDL_MapRGB(fonction->format,120,150,150));
    posfonction.x=0;
    posfonction.y=0;

     //gradeh
    gradeh=SDL_CreateRGBSurface(SDL_HWSURFACE,largeur,gr,32,0,0,0,0);
     SDL_FillRect(gradeh,NULL,SDL_MapRGB(gradeh->format,0,50,25));
    posgradeh.x=0;
    posgradeh.y=0;
    for(i=0;i<24;i++)
    {
     posgradeh.y+=o;
     SDL_BlitSurface(gradeh,NULL,screen,&posgradeh);
    }
    //gradev
     gradev=SDL_CreateRGBSurface(SDL_HWSURFACE,1,hauteur,32,0,0,0,0);
     SDL_FillRect(gradev,NULL,SDL_MapRGB(gradev->format,0,50,25));
     posgradev.x=0;
    posgradev.y=0;
    for(i=0;i<48;i++)
    {
    	posgradev.x+=o;
    	SDL_BlitSurface(gradev,NULL,screen,&posgradev);
    }
     SDL_BlitSurface(dD,NULL,screen,&posdD);
    SDL_BlitSurface(gG,NULL,screen,&posgG);
    //fonction
    Pa=-24;
    for(i=0;i<48*100;i++)
    {
       posfonction.x=screen->w/2+(Pa)*o;
       posfonction.y=screen->h/2-(fonctioon(Pa))*o;
       Pa+=0.01;
       SDL_BlitSurface(fonction,NULL,screen,&posfonction);
    }

    SDL_Flip(screen);
     int continu=1;
     SDL_EnableKeyRepeat(100,100);
     //start of while
    while(continu)
     {
     	SDL_Event(eve);
     	SDL_WaitEvent(&eve);
     	//start of switch
     	switch(eve.type)
     	{
     		case SDL_QUIT:
     		continu=0;
     		break;
     		case SDL_KEYDOWN :
     		switch(eve.key.keysym.sym)
     		{

     		case SDLK_i:
     		if(rem<3)
     		{ aidefonction=0;
     		    aide=0;
     		    aide2=0;
     		     aidefonctionu=0;
     		     aideu=0;
     		     aide2u=0;
     		    ff+=1*2;
 				 Pa=-24;
 				 o+=14*2;
     		    SDL_BlitSurface(back,NULL,screen,&posback);
               //dD
                d+=2*2;
    			dD=SDL_CreateRGBSurface(SDL_HWSURFACE,d,hauteur,32,0,0,0,0);
    			 SDL_FillRect(dD,NULL,SDL_MapRGB(dD->format,255,0,0));
     			posdD.x=screen->w/2-dD->w/2;
     			 recald=screen->w/2-dD->w/2;
    			posdD.y=screen->h/2-dD->h/2;
   				 //gG
        		gG=SDL_CreateRGBSurface(SDL_HWSURFACE,largeur,d,32,0,0,0,0);
     			SDL_FillRect(gG,NULL,SDL_MapRGB(gG->format,255,0,0));
    			posgG.x=screen->w/2-gG->w/2;
    			posgG.y=screen->h/2-gG->h/2;
    			recaly=posgG.y;
     			//gradeh
    			gr+=1*2;

			    gradeh=SDL_CreateRGBSurface(SDL_HWSURFACE,largeur,gr,32,0,0,0,0);
    			 SDL_FillRect(gradeh,NULL,SDL_MapRGB(gradeh->format,0,50,25));
   				 posgradeh.x=0;
    			posgradeh.y=0;
    			for(i=0;i<24;i++)
    			{
     				posgradeh.y+=o;
    				 SDL_BlitSurface(gradeh,NULL,screen,&posgradeh);
    			}
    			//gradev
     			gradev=SDL_CreateRGBSurface(SDL_HWSURFACE,gr,hauteur,32,0,0,0,0);
     			SDL_FillRect(gradev,NULL,SDL_MapRGB(gradev->format,0,50,25));
    			 posgradev.x=0;
   				 posgradev.y=0;
   				 for(i=0;i<48;i++)
    			{
    				posgradev.x+=o;
    				SDL_BlitSurface(gradev,NULL,screen,&posgradev);
   				 }
   					  SDL_BlitSurface(dD,NULL,screen,&posdD);
   					  SDL_BlitSurface(gG,NULL,screen,&posgG);
    			//fonction

            	fonction=SDL_CreateRGBSurface(SDL_HWSURFACE,ff,ff,32,0,0,0,0);
               SDL_FillRect(fonction,NULL,SDL_MapRGB(fonction->format,120,150,150));
    			for(i=0;i<48*100;i++)
   				 {
    			   posfonction.x=screen->w/2+(Pa)*(o);
    			   posfonction.y=screen->h/2-(fonctioon(Pa))*(o);
       				Pa+=0.01;
       				SDL_BlitSurface(fonction,NULL,screen,&posfonction);
    			}
    			rem++;
    		    }
     		 break;
     		 case SDLK_k:
     		     if( rem>0)
     		     {aidefonction=0;
     		     aidefonctionu=0;
     		     aideu=0;
     		     aide2u=0;
     		         aide=0;
     		     aide2=0;
     		     ff-=1*2;
 				 Pa=-24;
 				 o-=14*2;
     		    SDL_BlitSurface(back,NULL,screen,&posback);
               //dD
                d-=2*2;
    			dD=SDL_CreateRGBSurface(SDL_HWSURFACE,d,hauteur,32,0,0,0,0);
    			 SDL_FillRect(dD,NULL,SDL_MapRGB(dD->format,255,0,0));
     			posdD.x=screen->w/2-dD->w/2;
     			 recald=screen->w/2-dD->w/2;
    			posdD.y=screen->h/2-dD->h/2;
   				 //gG
        		gG=SDL_CreateRGBSurface(SDL_HWSURFACE,largeur,d,32,0,0,0,0);
     			SDL_FillRect(gG,NULL,SDL_MapRGB(gG->format,255,0,0));
    			posgG.x=screen->w/2-gG->w/2;
    			posgG.y=screen->h/2-gG->h/2;
    			    			recaly=posgG.y;

     			//gradeh
    			gr-=1*2;

			    gradeh=SDL_CreateRGBSurface(SDL_HWSURFACE,largeur,gr,32,0,0,0,0);
    			 SDL_FillRect(gradeh,NULL,SDL_MapRGB(gradeh->format,0,50,25));
   				 posgradeh.x=0;
    			posgradeh.y=0;
    			for(i=0;i<24;i++)
    			{
     				posgradeh.y+=o;
    				 SDL_BlitSurface(gradeh,NULL,screen,&posgradeh);
    			}
    			//gradev
     			gradev=SDL_CreateRGBSurface(SDL_HWSURFACE,gr,hauteur,32,0,0,0,0);
     			SDL_FillRect(gradev,NULL,SDL_MapRGB(gradev->format,0,50,25));
    			 posgradev.x=0;
   				 posgradev.y=0;
   				 for(i=0;i<48;i++)
    			{
    				posgradev.x+=o;
    				SDL_BlitSurface(gradev,NULL,screen,&posgradev);
   				 }
   					  SDL_BlitSurface(dD,NULL,screen,&posdD);
   					  SDL_BlitSurface(gG,NULL,screen,&posgG);
    			//fonction

            	fonction=SDL_CreateRGBSurface(SDL_HWSURFACE,ff,ff,32,0,0,0,0);
               SDL_FillRect(fonction,NULL,SDL_MapRGB(fonction->format,120,150,150));
    			for(i=0;i<48*100;i++)
   				 {
    			   posfonction.x=screen->w/2+(Pa)*(o);
    			   posfonction.y=screen->h/2-(fonctioon(Pa))*(o);
       				Pa+=0.01;
       				SDL_BlitSurface(fonction,NULL,screen,&posfonction);
    			}
     	   rem--;}
     	 break;
         case SDLK_RIGHT:
             if(le==1)
                aide=aide2;
                le=0;
     		    SDL_BlitSurface(back,NULL,screen,&posback);
               //dD

    			dD=SDL_CreateRGBSurface(SDL_HWSURFACE,d,hauteur,32,0,0,0,0);
    			 SDL_FillRect(dD,NULL,SDL_MapRGB(dD->format,255,0,0));
                recald-=14;
     			posdD.x-=14;

    			posdD.y=(screen->h/2-dD->h/2);
   				 //gG
        		gG=SDL_CreateRGBSurface(SDL_HWSURFACE,largeur,d,32,0,0,0,0);
     			SDL_FillRect(gG,NULL,SDL_MapRGB(gG->format,255,0,0));
    			posgG.x=(screen->w/2-gG->w/2);
    			posgG.y=(screen->h/2-gG->h/2);
                posgG.y=recaly;

     			//gradeh


			    gradeh=SDL_CreateRGBSurface(SDL_HWSURFACE,largeur,gr,32,0,0,0,0);
    			 SDL_FillRect(gradeh,NULL,SDL_MapRGB(gradeh->format,0,50,25));
   				 posgradeh.x=0;
    			 if(up==0)
    			 posgradeh.y=aideu;
    			 else
    			 posgradeh.y=aide2u;
    			for(i=0;i<24;i++)
    			{
     				posgradeh.y+=o;
    				 SDL_BlitSurface(gradeh,NULL,screen,&posgradeh);
    			}
    			//gradev
     			gradev=SDL_CreateRGBSurface(SDL_HWSURFACE,gr,hauteur,32,0,0,0,0);
     			SDL_FillRect(gradev,NULL,SDL_MapRGB(gradev->format,0,50,25));

    			 if(aide==-o)
                    aide=0;

    			 aide-=14;

    			 posgradev.x=aide;

   				 posgradev.y=0;
   				 for(i=0;i<48;i++)
    			{

    				posgradev.x+=o;
    				SDL_BlitSurface(gradev,NULL,screen,&posgradev);
   				 }
   					  SDL_BlitSurface(dD,NULL,screen,&posdD);
   					  SDL_BlitSurface(gG,NULL,screen,&posgG);
    			//fonction
    			Pa=-24;
    			aidefonction+=14;
    			fonction=SDL_CreateRGBSurface(SDL_HWSURFACE,ff,ff,32,0,0,0,0);
               SDL_FillRect(fonction,NULL,SDL_MapRGB(fonction->format,120,150,150));
    			for(i=0;i<48*100;i++)
   				 {
    			   posfonction.x=screen->w/2+(Pa)*(o);
    			   posfonction.x-=aidefonction;
    			   posfonction.y=screen->h/2-(fonctioon(Pa))*(o);
    			   posfonction.y-=aidefonctionu;
       				Pa+=0.01;
       				SDL_BlitSurface(fonction,NULL,screen,&posfonction);

    			}
          break;
           case SDLK_LEFT:
               if(le==0)
               aide2=aide;
               le=1;
           SDL_BlitSurface(back,NULL,screen,&posback);
               //dD

    			dD=SDL_CreateRGBSurface(SDL_HWSURFACE,d,hauteur,32,0,0,0,0);
    			 SDL_FillRect(dD,NULL,SDL_MapRGB(dD->format,255,0,0));
     			posdD.x+=14;
     			recald+=14;
                if(recald<0)
                posdD.x=-20;
                else
                    posdD.x=recald;
    			posdD.y=(screen->h/2-dD->h/2);
   				 //gG
        		gG=SDL_CreateRGBSurface(SDL_HWSURFACE,largeur,d,32,0,0,0,0);
     			SDL_FillRect(gG,NULL,SDL_MapRGB(gG->format,255,0,0));
    			posgG.x=(screen->w/2-gG->w/2);
    			posgG.y=(screen->h/2-gG->h/2);
                posgG.y=recaly;

     			//gradeh


			    gradeh=SDL_CreateRGBSurface(SDL_HWSURFACE,largeur,gr,32,0,0,0,0);
    			 SDL_FillRect(gradeh,NULL,SDL_MapRGB(gradeh->format,0,50,25));
   				 posgradeh.x=0;

    			 if(up==0)
    			 posgradeh.y=aideu;
    			 else
    			 posgradeh.y=aide2u;
    			for(i=0;i<24;i++)
    			{
     				posgradeh.y+=o;
    				 SDL_BlitSurface(gradeh,NULL,screen,&posgradeh);
    			}
    			//gradev
     			gradev=SDL_CreateRGBSurface(SDL_HWSURFACE,gr,hauteur,32,0,0,0,0);
     			SDL_FillRect(gradev,NULL,SDL_MapRGB(gradev->format,0,50,25));
    			 if(aide2==0)
                    aide2=-o;
    			 aide2+=14;
    			 posgradev.x=aide2;

   				 posgradev.y=0;
   				 for(i=0;i<48;i++)
    			{
    				posgradev.x+=o;
    				SDL_BlitSurface(gradev,NULL,screen,&posgradev);
   				 }
   					  SDL_BlitSurface(dD,NULL,screen,&posdD);
   					  SDL_BlitSurface(gG,NULL,screen,&posgG);
    			//fonction

            	Pa=-24;
    			aidefonction-=14;
    			fonction=SDL_CreateRGBSurface(SDL_HWSURFACE,ff,ff,32,0,0,0,0);
               SDL_FillRect(fonction,NULL,SDL_MapRGB(fonction->format,120,150,150));
    			for(i=0;i<48*100;i++)
   				 {
    			   posfonction.x=screen->w/2+(Pa)*(o);
    			   posfonction.x-=aidefonction;
    			   posfonction.y=screen->h/2-(fonctioon(Pa))*(o);
    			     posfonction.y-=aidefonctionu;
       				Pa+=0.01;
       				SDL_BlitSurface(fonction,NULL,screen,&posfonction);

    			}

          break;
           case SDLK_DOWN:
             if(up==1)
                aideu=aide2u;
                up=0;
     		    SDL_BlitSurface(back,NULL,screen,&posback);
               //dD

    			dD=SDL_CreateRGBSurface(SDL_HWSURFACE,d,hauteur,32,0,0,0,0);
    			 SDL_FillRect(dD,NULL,SDL_MapRGB(dD->format,255,0,0));

     			posdD.x=recald;
    			posdD.y=(screen->h/2-dD->h/2);
   				 //gG
        		gG=SDL_CreateRGBSurface(SDL_HWSURFACE,largeur,d,32,0,0,0,0);
     			SDL_FillRect(gG,NULL,SDL_MapRGB(gG->format,255,0,0));
    			posgG.x=(screen->w/2-gG->w/2);
    			posgG.y-=14;
    			recaly-=14;

     			//gradeh

			    gradeh=SDL_CreateRGBSurface(SDL_HWSURFACE,largeur,gr,32,0,0,0,0);
    			 SDL_FillRect(gradeh,NULL,SDL_MapRGB(gradeh->format,0,50,25));
   				 if(aideu==-o)
                    aideu=0;

    			 aideu-=14;

   				 posgradeh.x=0;
    			posgradeh.y=aideu;
    			for(i=0;i<24;i++)
    			{
     				posgradeh.y+=o;
    				 SDL_BlitSurface(gradeh,NULL,screen,&posgradeh);
    			}
    			//gradev
     			gradev=SDL_CreateRGBSurface(SDL_HWSURFACE,gr,hauteur,32,0,0,0,0);
     			SDL_FillRect(gradev,NULL,SDL_MapRGB(gradev->format,0,50,25));


                 if(le==0)
    			 posgradev.x=aide;
    			 else
    			 posgradev.x=aide2;

   				 posgradev.y=0;
   				 for(i=0;i<48;i++)
    			{

    				posgradev.x+=o;
    				SDL_BlitSurface(gradev,NULL,screen,&posgradev);
   				 }
   					  SDL_BlitSurface(dD,NULL,screen,&posdD);
   					  SDL_BlitSurface(gG,NULL,screen,&posgG);
    			//fonction
    			Pa=-24;
    			aidefonctionu+=14;
    			fonction=SDL_CreateRGBSurface(SDL_HWSURFACE,ff,ff,32,0,0,0,0);
               SDL_FillRect(fonction,NULL,SDL_MapRGB(fonction->format,120,150,150));
    			for(i=0;i<48*100;i++)
   				 {
    			   posfonction.x=screen->w/2+(Pa)*(o);
                    posfonction.x-=aidefonction;
    			   posfonction.y=screen->h/2-(fonctioon(Pa))*(o);
    			   posfonction.y-=aidefonctionu;
       				Pa+=0.01;
       				SDL_BlitSurface(fonction,NULL,screen,&posfonction);

    			}
    			break;
    			case SDLK_UP:
             if(up==0)
                aide2u=aideu;
                up=1;
     		    SDL_BlitSurface(back,NULL,screen,&posback);
               //dD

    			dD=SDL_CreateRGBSurface(SDL_HWSURFACE,d,hauteur,32,0,0,0,0);
    			 SDL_FillRect(dD,NULL,SDL_MapRGB(dD->format,255,0,0));

     			posdD.x=recald;
    			posdD.y=(screen->h/2-dD->h/2);
   				 //gG
        		gG=SDL_CreateRGBSurface(SDL_HWSURFACE,largeur,d,32,0,0,0,0);
     			SDL_FillRect(gG,NULL,SDL_MapRGB(gG->format,255,0,0));
    			posgG.x=(screen->w/2-gG->w/2);
    			posgG.y+=14;
    			recaly+=14;
    			if(recaly<0)
                    posgG.y=-20;
                else
                    posgG.y=recaly;
     			//gradeh

			    gradeh=SDL_CreateRGBSurface(SDL_HWSURFACE,largeur,gr,32,0,0,0,0);
    			 SDL_FillRect(gradeh,NULL,SDL_MapRGB(gradeh->format,0,50,25));
   				 if(aide2u==0)
                    aide2u=-o;

    			 aide2u+=14;

   				 posgradeh.x=0;
    			posgradeh.y=aide2u;
    			for(i=0;i<24;i++)
    			{
     				posgradeh.y+=o;
    				 SDL_BlitSurface(gradeh,NULL,screen,&posgradeh);
    			}
    			//gradev
     			gradev=SDL_CreateRGBSurface(SDL_HWSURFACE,gr,hauteur,32,0,0,0,0);
     			SDL_FillRect(gradev,NULL,SDL_MapRGB(gradev->format,0,50,25));


                 if(le==0)
    			 posgradev.x=aide;
    			 else
    			 posgradev.x=aide2;

   				 posgradev.y=0;
   				 for(i=0;i<48;i++)
    			{

    				posgradev.x+=o;
    				SDL_BlitSurface(gradev,NULL,screen,&posgradev);
   				 }
   					  SDL_BlitSurface(dD,NULL,screen,&posdD);
   					  SDL_BlitSurface(gG,NULL,screen,&posgG);
    			//fonction
    			Pa=-24;
    			aidefonctionu-=14;
    			fonction=SDL_CreateRGBSurface(SDL_HWSURFACE,ff,ff,32,0,0,0,0);
               SDL_FillRect(fonction,NULL,SDL_MapRGB(fonction->format,120,150,150));
    			for(i=0;i<48*100;i++)
   				 {
    			   posfonction.x=screen->w/2+(Pa)*(o);
                    posfonction.x-=aidefonction;
    			   posfonction.y=screen->h/2-(fonctioon(Pa))*(o);
    			   posfonction.y-=aidefonctionu;
       				Pa+=0.01;
       				SDL_BlitSurface(fonction,NULL,screen,&posfonction);

    			}
    			break;

     	}
     	break;}
     	// end of switch


        SDL_BlitSurface(fonction,NULL,screen,&posfonction);
        SDL_Flip(screen);
     }// end of while

     SDL_FreeSurface(fonction);
     SDL_Quit();
     return EXIT_SUCCESS;
}


