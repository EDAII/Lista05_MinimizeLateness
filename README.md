<h1>Algoritmo Minimize Lateness </h4> <br>
<p align="center">    
    <img src="https://kartikkukreja.files.wordpress.com/2013/11/scheduling-to-minimize-lateness.png" width=700 height=400>
</p>

## Contribuidores
| Nome	| Matrícula	|
|--|--|
| Adrianne Alves da Silva | 16/0047595 |
| Lucas Arthur Lermen | 16/0012961 |


## Apresentação

Este repositório apresenta um algoritmo ambicioso para organização de tarefas ou eventos, considerando a deadline e a redução de atraso, o Scheduling to minimize lateness, escrito em linguagem c, para fins didáticos na disciplina de Estrutura de dados 2. Consiste em uma atividade apresentada como avaliação parcial da disciplina de Estrutura de dados 2 do curso de Engenharia de software da Universidade de Brasília (UnB), Campus de Engenharias - Faculdade do Gama (FGA).

## Sobre algoritmos ambiciosos 

Algoritmos ambiciosos são algorítmos que procuram a escolha ótima ou procuram a opção que parece melhor naquele momento. Em geral, resolve problemas complexos e tomam decisões locais ambiciosas, pois não volta atrás.

## Sobre Scheduling Minimize Lateness

Esse algorítmo se destina a problemas que envolvem o comportamento básico relacionado ao processamento de tarefas, de maneira que se considera a duração da mesma e o prazo de entrega, por assim dizer. É preciso lembrar que o atraso consiste na quantidade de tempo que a execução de uma atividade utrapassa o prazo de deadline. Assim, o principal objetivo dessa metodologia é escalar essas tarefas de modo que garanta a minimização do atrazo máximo desse conjunto.

### Funcionamento

Inicialmente, é preciso que essas tarefas sejam colocadas em alguma ordem, como por exemplo, pelo tempo de processamento, deadline, entre outros. A melhor metodologia é ordenar essas atividades pela ordem crescente das deadlines.Um pseudocódigo básico que resume essa execução decorre do seguinte: 

> sort Jobs

> t = 0 

> para j=1 ate n

> Aloca job no intervalo [t, t+tj]


>    sj = t #incial

>    fj = t + tj #final

>  t = t + tj 

>  saída do intervalo [sj, tj]

### Como utilizar

Levando em consideração que o sistema usado seja linux, basta entrar na pasta pelo terminal e digitar gcc -o exec minMaxLatenessAlg.cpp para utilizar o algoritmo.

### Repositório original 
https://github.com/LucasLermen/Lista5-MinimizeLateness/edit/master/README.md
