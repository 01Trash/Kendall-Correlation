#include <cstdlib>    
#include "sabitler.hpp"
#include "KouGps.hpp"
#define FREE_ARG char*
#define NR_END 1
#define ROTATE(a,i,j,k,l) g=a[i][j];h=a[k][l];a[i][j]=g-s*(h+g*tau);\
	a[k][l]=h+s*(g-h*tau);
#define  a_wgs          6378137.0           //WGS-84 earth's semi major axis
#define  b_wgs          6356752.31425       //WGS-84 earth's semi minor axis
///*** zorlamasýz dengeleme sonucunda ki iz{QvvP} deðerine göre belirlenen 
///    bir G matrisi ile datum belirleme.
//______________________________________________________________________________

//___________________________________________________________________________
void denge(char *GIRIS, char *CIKIS) {
     const int b=2000;
     int i, j, k,n, toplam; 

	 
     string NN[2000],DN[2000], NS[2000]; 

     double  X[b], Y[b], aa, bb,K,
            
              bos ;
		
    ifstream grs( GIRIS ) ;
    ofstream cks( CIKIS ) ;



    cks<<" \n\n\n" ;
    cks<<" ********************* veriler*******************"<<" \n\n\n" ; 
     
    grs>> DN[0] ;
    grs >> n ;  

    grs>> DN[0] >> DN[0] >> DN[0] ;
    i=0;
    for(i=1; i<=n;i++ ){
         
     
                                                            
      grs >> NN[i] >> X[i] >> Y[i];  
    
      
     
      frmt( cks," "  ,NN[i] , "###"),cks<<" \t" ;    
      frmt( cks," "  ,X[i], "###########.####"),cks<<" \t"; 
      frmt( cks," "  ,Y[i],  "###########.####"),cks<<" \t\n";
     
    
    
        //cks<<" \n" ;
        }
    
//Kendall Korelasyon Katsayýsý
        cks<<" Kendal "<<" \n\n\n" ; 
		toplam=0;
		 for(i=1; i<=n;i++ ){
                  frmt( cks,"i= "  ,i, "##########"),cks<<" \t\n"; 
			for(j=1; j<=n;j++ ) if(i<j){ 
			frmt( cks,"j= "  ,j, "##########"),cks<<" \t"; 
			aa=0;
			aa=X[i]-X[j];
			frmt( cks," "  ,aa, "###########.####"),cks<<" \t"; 
			if(aa>0.00000) aa=1;
			else if(aa<0.00000) aa=-1;
			else aa=0;
			
			frmt( cks," "  ,aa, "###########.####"),cks<<" \t\n"; 
			
			
			
			bb=0;
			cks<<" \t\t\t"; 
		    bb=Y[i]-Y[j];
			frmt( cks," "  ,bb, "###########.####"),cks<<" \t"; 
			if(bb>0.00000) bb=1;
			else if(bb<0.00000) bb=-1;
			else bb=0;
			frmt( cks," "  ,bb, "###########.####"),cks<<" \t\n"; 
			
			
			toplam+=(aa*bb);
			frmt( cks,"(aa*bb)= "  ,(aa*bb), "###########.####"),cks<<" \n"; 
			}
			cks<<" \n\n\n" ;
			K=(2.0/(n*(n-1.0)))*toplam;
		 }
		
		
		
	   cks<<" \n\n\n" ;
		
		frmt( cks,"K= "  ,K, "###########.####"),cks<<" \n"; 
		
		
       
      
   } 



  

//______________________________________________________________________________


int main(int argc, char *argv[]){
   system("color 4b") ;

   
   denge("bitirme.txt", "bitirme_cikis.txt" ); 

   
           
    system("PAUSE");
    return EXIT_SUCCESS;
    
}

