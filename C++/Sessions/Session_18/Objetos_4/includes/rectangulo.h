#ifndef RECTANGULO_H  // Si no se ha definido RECTANGULO_H, define el siguiente
                      // bloque
#define RECTANGULO_H  // Evita que el archivo sea incluido m s de una vez

// Definici¢n de la clase Rectangulo
class Rectangulo {
 private:
  double ancho;  // Atributo privado: ancho del rect ngulo
  double alto;   // Atributo privado: alto del rect ngulo

 public:
  // Constructor sin par metros: inicializa el rect ngulo con valores por
  // defecto (1,1)
  Rectangulo();

  // Constructor con par metros: inicializa el rect ngulo con los valores dados
  // para ancho y alto
  Rectangulo(double a, double b);

  // M‚todo para calcular el  rea del rect ngulo: area = ancho * alto
  double area();

  // M‚todo para calcular el per¡metro del rect ngulo: perimetro = 2 * (ancho +
  // alto)
  double perimetro();

  // M‚todo para imprimir las dimensiones del rect ngulo
  void imprimir();
};

// Fin de la definici¢n del header guardado por la directiva de preprocesador
#endif
