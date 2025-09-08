- Problema da mochila é um container loading problem
- **Enunciado:** Imagine que você tem uma mochila com uma capacidade máxima de peso limitada. Há um conjunto de itens disponíveis, e cada item possui um valor e um peso específicos. O seu objetivo é escolher quais itens colocar na mochila de modo que o valor total dos itens dentro da mochila seja o maior possível, sem exceder a capacidade de peso da mochila.

- Podemos resolver esse problema das seguintes formas:
	- Força bruta: Testar todos os subconjuntos de itens, ou seja, todas as possibilidades 
	- Guloso: Vai analisar valor ou peso, vai escolher o melhor primeiro, vai escolhendo o melhor por subconjunto (nem sempre dá ótimo)
	- Programação dinâmica: Guarda resultados em uma tabela
	
- **Enunciado simplificado:** Imagine que você é um ladrão e invadiu uma joalheria. Você tem uma mochila que aguenta um peso máximo. Na sua frente, há várias joias, cada uma com um peso e um valor. Sua tarefa é decidir quais joias levar para maximizar o valor total dentro da sua mochila, sem exceder o limite de peso.

- Este é o **Problema da Mochila 0/1**, onde para cada item, você tem duas opções: ou você o pega inteiro (1) ou você o deixa (0). Não é possível pegar uma parte de um item.

- Na vida real eu posso ter os seguintes itens:
	- Um livro de calculo 1, que pesa 1kg e custa 60 reais
	- Um notebook que pesa 3kg e custa 1000 reais
	- Um caderno que pesa 2kg e custa 30 reais
	- Uma marmita de que pesa 2kg e custa 15 reais
Porém minha mochila só aguenta 5kg, então teria que escolher os mais caros porque meu objetivo é vender eles na feira e não pode pesar mais de 5kg

- A entrada deve ser composta por: 
	- Lista de itens, onde cada item tem (peso, valor)
	- n = número de itens
	- capacidade = peso máximo que a mochila suporta
- A saída será:
	- O valor máximo que pode ser obtido respeitando a capacidade da mochila
- Temos que escolher os itens focando em maximizar 

# Problema da mochila por Força Bruta
Tag: [[Força bruta]]

- Na força bruta utilizamos **todas as combinações possíveis** de itens, para cada item podemos coloca-lo ou não na mochila
- item(peso, valor)
- Complexidade 2ˆn (A complexidade cresce muito rápida)
- Ela percorre todas as possibilidades de escolha entre 3 itens sendo: Item 1 (peso:2 e valor:12), item 2 (peso:1 e valor:10) e item 3(peso:3 e valor: 20), após percorrer todos os itens e possibilidades ele vê qual a melhor e que se adequa ao peso limite, nesse caso a melhor solução é a escolha dos itens 1 e 3 (peso= 5 e o valor=32)
- C = Capacidade máxima
- Complexidade: 2ˆn (n = numero de itens)

# Problema da mochila por gulosa
Tag: [[Gulosa]]
- Cada objeto tem um peso e um lucro/valor
- A mochila tem um máximo de peso 
- Restrição o peso dos objetos na mochila deve ser menor ou igual a 15 (se o valor de capacidade máxima for 15)
![[Pasted image 20250828213951.png]]
- Ratio = razão entre o valor e o peso
- Reordena os objetos do maior ratio para o menor
- Vai escolhendo até o valor passar de 15 kg, quando passa de 15kg não pega o objeto
```


```

Escolher os maiores ratios que juntos não excedem o peso 
Mochila
Caixeiro viajante
Pendrive do simulado
Linha de montagem
