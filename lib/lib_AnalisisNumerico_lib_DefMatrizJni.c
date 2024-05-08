#include<jni.h>
/*
 * Class:     MatrizJni_lib_MatrizCalculator
 * Method:    resolverMatriz
 * Signature: ([FI)[F
 */
JNIEXPORT jfloatArray JNICALL Java_MatrizJni_lib_MatrizCalculator_resolverMatriz
  (JNIEnv * env, jobject obj, jfloatArray matriz, jint size){

   float factor;
   jsize len = (*env)->GetArrayLength(env, matriz);

   jfloat *matrizC = (*env)->GetFloatArrayElements(env, matriz, NULL);

   float matriz2D[size][size+1];

   for (int i = 0; i < size; i++) {
        for (int j = 0; j <= size; j++) {
            matriz2D[i][j] = matrizC[i * (size + 1) + j];
        }
   }

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
 
 (*env)->ReleaseFloatArrayElements(env, matriz, matrizC, 0);

    jfloatArray resultado = (*env)->NewFloatArray(env, size * (size + 1));

    (*env)->SetFloatArrayRegion(env, resultado, 0, size * (size + 1), (jfloat *) matriz2D);

    return resultado;

}
