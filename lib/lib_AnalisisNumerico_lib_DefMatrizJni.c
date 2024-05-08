
#include <jni.h>
/*
 * Class:     lib_AnalisisNumerico_lib_DefMatrizJni
 * Method:    resolverMatriz
 * Signature: ([FI)[F
 */
JNIEXPORT jfloatArray JNICALL Java_lib_1AnalisisNumerico_lib_DefMatrizJni_resolverMatriz
  (JNIEnv * env, jobject obj, jfloatArray matriz, jint size){
/*
* Definicion de variables que usaremos para la aplicacion del algoritmo
*/



  float factor;
   jsize len = (*env)->GetArrayLength(env, matriz);


   jfloat *matrizC = (*env)->GetFloatArrayElements(env, matriz, NULL);

/*
* Convertimos al arreglo en matriz
*/
   float matriz2D[size][size+1];



   for (int i = 0; i < size; i++) {
        for (int j = 0; j <= size; j++) {
            matriz2D[i][j] = matrizC[i * (size + 1) + j];
        }
   }

/*
* Ciclos para la aplicacion del metodo de eliminacion hacia adelante de Gauss-Jordan
*/

   for (int i = 0; i < size; i++) {
        for (int j = 0; j < size; j++) {
            if (i != j) {
                float factor = matriz2D[j][i] / matriz2D[i][i];
                for (int k = 0; k <= size; k++) {
                    matriz2D[j][k] -= factor * matriz2D[i][k];
                }
            }
        }
    }

   for (int i = 0; i < size; i++) {
        float factor = matriz2D[i][i];
        for (int j = 0; j <= size; j++) {
            matriz2D[i][j] /= factor;
        }
    }

/*
* Devolvemos el resultado en un jfloatArray con la matriz identidad y los resultados de las incognitas
*/

 (*env)->ReleaseFloatArrayElements(env, matriz, matrizC, 0);

    jfloatArray resultado = (*env)->NewFloatArray(env, size * (size + 1));

    (*env)->SetFloatArrayRegion(env, resultado, 0, size * (size + 1), (jfloat *) matriz2D);

    return resultado;

}
