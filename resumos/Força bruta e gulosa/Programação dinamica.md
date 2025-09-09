- Otimização achar a melhor solução
- Só serve para otimização, achar a melhor opção
- É basicamente uma derivada (de cálculo kkkk)
-  A programação dinâmica é uma técnica de otimização que divide um problema complicado em subproblemas sobrepostos 

# Explicando programação dinamica com multiplicação de matrizes

- **Enunciado:** Tenho que realizar a multiplicação de matrizes abaixo:

| Matriz | Dimensão |
| ------ | -------- |
| A0     | 20x35    |
| A1     | 35x15    |
| A2     | 15x10    |
| A3     | 10x55    |
	**- Como fazer:** 
		- Realizar 1º os subproblemas com 2 matrizes:
			- A0 x A1 -> 20 . 35 . 15 = 10500 com dimensões 20x15 (exclui o que repete)
			- A1 x A2 -> 35 . 15 . 10 = 5250 com dimensões 35x10
			- A2 x A3 -> 15 . 10 . 55 = 8250 com dimensões 15x55
		-Realizar depois os subproblemas com 3 matrizes:
				- (A0 . A1) . A2 -> já temos (A0 . A1) que é 10500 e tem dimensões 20x15
					- Agora vamos descobrir quanto é (A0 . A1) . A2: 20x15(dimensão a0a1) . 15x10(dimensão A2) -> 20 . 15 . 10 = 3000 com dimensões 20x10
					 - Depois somamos (A0A1) + (A0.A1) . A2= 10500 + 3000 = 13500 e dimensões 20x10
				- A0 . (A1 . A2) -> já temos (A1 . A2) que é 5250 e tem dimensões 35x10
					- Agora vamos descobrir quanto é A0 (A1 . A2): 35x10 (dimensões a1a2) . 20x35 (dimensões A0) = 20.35.10=  7000 -> resulta em 7000 e dimensões 10x35
					- Depois somamos (A1 . A2) + (A1 . A2) . A0 = 5250 + 7000 = 12250 e dimensões 10x35
				- (A1 . A2) . A3 -> já temos (A1 . A2) que é 5250 e tem dimensões 35x10
					- Agora vamos descobrir quanto é (A1 . A2) . A3: 35x10 (dimensões a1a2) . 10x55(dimensões A3) = 35 . 10 . 55 = 19250 -> resulta em 19250 e dimensões 35x55
					- Depois somamos (A1 . A2) + (A1 . A2) . A3 = 5250 + 19250 = 24500 e dimensões 35x55
				- (A1) . (A2 . A3) -> já temos (A2 . A3) e tem dimensões 15x55
					- Agora vamos descobrir quanto é A1 . (A2 . A3): 35x15(dimensão A1) . 15x55(dimensão a2a3) -> 35 . 15 . 55 = 28875 com dimensões 35x55
					- Depois somamos (A2 . A3) + A1 . (A2 . A3) = 8250 + 28875 = 37125 e dimensões 35x55
		- Realizar agora os subproblemas com 4 matrizes:
			- ((A0 . A1) . A2) . A3 -> já temos (A0 . A1) . A2 que é 13500 e tem dimensões 20x10
				- Agora vamos descobrir quanto é ((A0 . A1) . A2) . A3: 20x10(dimensão a0a1a2) . 10x55(dimensão A3) -> 20 . 10 . 55 = 11000 com dimensões 20x55
				- Depois somamos (A0 . A1) . A2 + ((A0 . A1) . A2) . A3 = 13500 + 11000 = 24500 e dimensões 20x55
			- (A0 . (A1 . A2)) . A3 -> já temos A0 . (A1 . A2) que é 12250 e tem dimensões 20x10
				- Agora vamos descobrir quanto é (A0 . (A1 . A2)) . A3: 20x10(dimensão a0a1a2) . 10x55(dimensão A3) -> 20 . 10 . 55 = 11000 com dimensões 20x55
				- Depois somamos (A0 . (A1 . A2)) + (A0 . (A1 . A2)) . A3 = 12250 + 11000 = 23250 e dimensões 20x55
			- (A0 . A1) . (A2 . A3) -> já temos (A0 . A1) que é 10500 e (A2 . A3) que é 8250
				- Agora vamos descobrir quanto é (A0 . A1) . (A2 . A3): 20x15(dimensão a0a1) . 15x55(dimensão a2a3) -> 20 . 15 . 55 = 16500 com dimensões 20x55
				- Depois somamos (A0 . A1) + (A2 . A3) + (A0 . A1) . (A2 . A3) = 10500 + 8250 + 16500 = 35250 e dimensões 20x55
			- A0 . ((A1 . A2) . A3) -> já temos (A1 . A2) . A3 que é 24500 e tem dimensões 35x55
				- Agora vamos descobrir quanto é A0 . ((A1 . A2) . A3): 20x35(dimensão A0) . 35x55(dimensão a1a2a3) -> 20 . 35 . 55 = 38500 com dimensões 20x55
				- Depois somamos (A1 . A2) . A3 + A0 . ((A1 . A2) . A3) = 24500 + 38500 = 63000 e dimensões 20x55
			- A0 . (A1 . (A2 . A3)) -> já temos A1 . (A2 . A3) que é 37125 e tem dimensões 35x55
				- Agora vamos descobrir quanto é A0 . (A1 . (A2 . A3)): 20x35(dimensão A0) . 35x55(dimensão a1a2a3) -> 20 . 35 . 55 = 38500 com dimensões 20x55
				- Depois somamos (A1 . (A2 . A3)) + A0 . (A1 . (A2 . A3)) = 37125 + 38500 = 75625 e dimensões 20x55

- **Explicação:** A programação dinâmica basicamente pega um problema e vai quebrando em problemas menores, resolve eles e vai juntando tudo. No caso da multiplicação de matrizes, em vez de sair multiplicando tudo de uma vez, a gente primeiro faz os subproblemas de 2 matrizes, depois usa isso pra resolver os de 3, depois os de 4 (usando as 3 calculadas anteriormente) . Ou seja: 2 matrizes = A0 x A1 (por exemplo), 3 matrizes (resultado 2 matrizes) . AX e 4 matrizes (3 matsrizes) . AX, faz por partes até encontrar o melhor resultado que nesse caso é (A0 . (A1.A2)) . A3 com custo 23250
		Subproblemas:
			- 2 matrizes
			- (2 matrizes) . 1 matriz
			-  (3 matrizes) . 1 matriz