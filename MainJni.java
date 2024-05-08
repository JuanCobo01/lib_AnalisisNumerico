package lib_AnalisisNumerico;
import lib_AnalisisNumerico.lib.DefMatrizJni;
public class MainJni{

    static {
      System.loadLibrary("CalMatrizG");
    }

  public MainJni(){
  float[] arreglo = {2,7,4.2f,-5,5,6.5f,10,-8,12,3.5f,-4,4.5f};
  int size=3;
  float[] resultado;

  DefMatrizJni miMatriz = new DefMatrizJni();
  resultado =  miMatriz.resolverMatriz(arreglo,size);


  for(int i=0 ; i < arreglo.length ; i++){
   System.out.println("Resultado="+resultado[i]);
  }



  }

  public static void main(String [] arguments){
        new MainJni();
  }

}
