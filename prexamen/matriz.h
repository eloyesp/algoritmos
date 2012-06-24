#define TF 20

typedef struct {
  int valores[TF][TF];
  int filas;
  int columnas;
} matriz;

void matriz_inicializar(matriz * const m, const int filas, const int columnas);
void matriz_mostrar(const matriz * const m);
void matriz_buscar_ceros(const matriz * const m);
int  matriz_valor(const matriz * const m, const int i, const int j);
