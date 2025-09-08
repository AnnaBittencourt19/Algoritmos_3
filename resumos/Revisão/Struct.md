- Uma Struct é como se fosse uma classe em Java, ela meio que cria um objeto com as características dele.
- Os structs são utilizados utilizados quando alguns dados pertencem a uma mesma coisa. (ex: o título, o autor e o número de páginas de um livro, as coordenadas de um ponto(x, y e z) ou a data (dia, mês e ano))
- Como criar uma Struct que armazena características de um livro? 
```
Struct livro{
	string titulo;
	string autor;
	int num_paginas; 
};
```
- Nesse bloco de código criamos uma Struct que armazena dados de um livro
- Mas como declarar valores para esses dados?
```
int main() {
	Livro livro1; // estamos instanciando um livro (criando um livro)
	livro1.titulo = "Dom Quixote"
	livro1.autor = "Miguel de Cervantes";
	livro1.num_paginas = 1033;
}
```
- Já nesse bloco de código criamos um livro, chamado livro1, para colocarmos valores nele temos que escrever livro1.dado_que_eu_quero.
- Caso fossemos criar outro livro poderíamos escrever Livro livro2 e declararíamos valores assim: livro2.dado_que_eu_quero.  

- Agora vamos fazer um Struct que representa pontos no plano cartesiano e vamos calcular a distância entre dois pontos. 
![[Calcular_distancia.svg]]
- No diagrama acima foi planejado como a Struct vai funcionar, ela se chamara ponto, terá os atributos: double coordenada_x e double coordenada_y, terá um método chamado calcular_distancia (Structs podem possuir métodos).
```
#include<cmath> //esse include chamar a biblioteca de matemática do c++ que vai possibilitar a realização do calculo da distancia entre dois pontos
```
```
struct Ponto { //criação da struct, contem double x e y (um mesmo ponto possuem coordenadas x e y)
	double x; 
	double y;
	//criando o método que calcula a distancia
	double distancia(Ponto outro){ //Ponto outro significa um outro ponto (que será definido quando o método for chamado)
		double dx = x - outro.x; //calculo da ditancia entre o x (que chamou o método e o x do outro ponto)
		double dy = y - outro.y; //caluclo da distancia y
		return sqrt(dx*dx + dy*dy); //retorna a distancia entre os dois pontos(sqrt é raíz quadrada)
	}
};

```
```
int main(){
//agora vamos criar dois pontos dentro da main
	Ponto p1; //criamos o primeiro ponto
	p1.x = 5; //definimos o valor de x do p1 como 5 (igual em Java)
	p1.y = 0;

	Ponto p2; //criamos o segundo ponto
	p2.x = 0; // o x de p2 será 0
	p2.y = 5;

	double dist = p1.distancia(p2); //aqui foi criada uma variavel para armazenar a distancia entre o p1 e o p2
	cout << Distancia entre p1 e p2: << dist << endl;
}

```
![[Media (1).jpeg]]

