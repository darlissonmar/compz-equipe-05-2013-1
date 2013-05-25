algoritmo "Fórmula de Bhaskara"
// Função : Esse algoritmo computa a formula de Bhaskara
// Autor : Equipe 05
// Data : 25/5/2013
// Seção de Declarações
var
   1x, x2, delta, a, b, c: real
inicio
      escreva("Informe a:"
      leia(a)
      escreva("Informe b:")
      leia(b)
      escreva("Informe c:")
      leia(c)
      
      delta <- b^2-(4*a*c)
      
      x1 <- (-1*(b)+ raizq(delta))/(2*a)
      x2 <- (-1*(b)+ raizq(delta))/(2*a)
      
      escreval("x1 = : ", x1:2:2)
      escreval("x2 = : ", x2:2:2)

      
fimalgoritmo
