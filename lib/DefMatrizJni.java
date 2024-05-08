package lib_AnalisisNumerico.lib;

 /*
* En esta clase se definen las funciones que tendra nuestra biblioteca
*
*/

 public class DefMatrizJni{

/*
* Se define el metodo resolverMatriz que recibe un arreglo de tipo flotante con
* los datos de la matriz a resolver , y recibe el tamaño de la matriz
* Posteriormente el metodo devuelve la matriz resuelta en un arreglo de tipo
* flotante.
*/

 public native float[] resolverMatriz(float[] matriz,int size);


}
