algoritmo "Fórmula de Bhaskara"
// Função : Esse algoritmo computa a formula de Bhaskara
// Autor : Equipe 05
// Data : 25/5/2013
/ Seção de Declarações
var
   x1, x2, delta, a, b, c: double
inicio
      escrever("Informe a:")
      ler(a)
      escrever("Informe b:")
      ler(b)
      escrever("Informe c:")
      ler(c)
      
      delta <- b^2-(4*a*c)
      
      x1 <- (-1*(b)+ raizq(delta))/(2*a)
      x2 <- (-1*(b)+ raizq(delta))/(2*a)
      
      escrever("x1 = : ", x1:2:2)
      escrever("x2 = : ", x2:2:2)

      
fimalgoritmo
