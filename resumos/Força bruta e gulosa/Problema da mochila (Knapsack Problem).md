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

# Problema da mochila por gulosa
Tag: [[Gulosa]]

- Na estratégia gulosa é feito o ratio entre valor/peso e esse ratio é coloca em ordem, a gulosa vai "pegando" do maior ratio para o menor até não caber mais coisas (não garante solução ótima)
- Complexidade: n

# Problema da mochila por dinâmica
Tag: [[Programação dinamica]]

- Divide o problema em subproblemas, garante a solução ótima
- Complexidade: n x c  (número de itens vezes capacidade da mochila)