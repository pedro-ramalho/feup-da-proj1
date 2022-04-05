# Panorama geral

## Objetivo

Tomando o papel de uma empresa de comércio, criar uma plataforma eletrónica de *crowdsourcing* para a entrega de mercadorias em zonas urbanas.

## Dados da empresa

A empresa tem o seu próprio armazém, onde recebe e mantém as mercadorias enviadas pelos fornecedores, que ficam a aguardar o transporte para o destino final.

A empresa realiza dois tipos de serviços: a **entrega normal** e a **entrega expresso**. Aos pedidos de transporte submetidos pelos fornecedores estão associados:
- o tipo de transporte contratado (normal ou expresso)
- o peso do pacote a transportar
- o volume do pacote a transportar
- o valor que a empresa receberá como recompensa por efetuar a entrega

## Tipos de entrega

Para as entregas normais, que são os pedidos em maior número e não precisam de ser entregues no mesmo dia, a empresa recorre à subcontratação de *estafetas*, que utilizam as as suas próprias viaturas para a realização de entregas.

Os estafetas registam-se na plataforma da empresa, indicando, entre outras informações:
- a matrícula da viatura
- a capacidade de transporte, definida em termos de peso máximo e volume máximo
- o custo de transporte pago pela empresa

Para as entregas expresso, a empresa mantém no armazém uma viatura de capacidade unitária, capaz de transportar um pedido de cada vez, independentemente do seu volume ou peso. Aos pedidos de entrega expresso está também associado um tempo de entrega, que corresponde ao tempo que a viatura da empresa leva para realizar o pedido, transportando a mercadoria até ao destino final e regressando ao armazém.

## Cenários para implementar

### Cenário 1 - otimização do número de estafetas

Considerando que os estafetas registados na plataforma estão sempre disponíveis para a realização de entregas normais, a empresa necessita de distribuir os pedidos de entregas normais acumulados para um determinado dia entre estafetas. A distribuição dos pedidos deve ser otimizada de forma a minimizar o número de estafetas a utilizar. Considera-se também que os estafetas só realizam uma viagem por dia, deve-se portanto maximizar o número de pedidos a transportar por um estafeta numa jornada.

Os pedidos que não puderem ser transportados num dia são descartados e retornam ao fornecedor.

Entre outros dados de entrada que se possam considerar, deve-se incluir:
- conjunto de estafetas registados, ***E***, com capacidade de volume ***We*** e de peso ***Pe***
- conjunto de pedidos a entregar, ***P***, com volume ***Vp*** e de peso ***Wp***

O objetivo principal é minimizar o número de estafetas para a entrega de todos os pedidos ou do maior número de pedidos, num dia.

### Cenário 2 - otimização do lucro da empresa

Considere agora que os estafetas cobram uma determinada quantia pelo número total de pedidos
entregues num dia, constituindo um custo para a empresa. Pela entrega de cada pedido, a
empresa também recebe uma receita, que lhe é paga por quem solicitou o pedido. Pretende-se,
portanto, dentre os estafetas registados na plataforma, selecionar aqueles que, para os pedidos
de um determinado dia, irão maximizar o lucro da empresa naquele dia, que será a diferença entre
a receita total dos pedidos entregues e a despesa correspondente ao custo total a ser pago pelas
entregas aos estafetas. Novamente, no caso de não haver capacidade total de transporte
suficiente ou das despesas serem superiores às receitas, os pedidos que não puderem ser
transportados num dia são descartados e retornam ao fornecedor.

Entre outros dados de entrada que se possam considerar, deve-se incluir:
- conjunto de estafetas registados, ***E***, com capacidade de volume ***We*** e custo ***Ce***
- conjunto de encomendas, ***P***, com volume ***Vp*** e recompensa ***Rp***

O objetivo principal é maximizar o lucro da empresa (diferença entre a receita total e o custo total) para a entrega de todos os pedidos ou do maior número de pedidos, num dia, pelos estafetas selecionados.

### Cenário 3 - otimização das entregas expresso

Como descrito anteriormente, para as entregas expresso, a empresa utiliza uma única viatura,
com capacidade unitária, realizando entregas de um único pedido a cada viagem,
independentemente do seu volume ou peso. Os pedidos passam a indicar um tempo estimado de
entrega, correspondendo ao tempo total necessário para o veículo da empresa entregar o pedido
no destino final e regressar ao armazém. As entregas expresso só podem ser entregues durante o
horário comercial, das 9:00 às 17:00. Para o máximo número de pedidos de entregas expresso, a
empresa pretende minimizar o tempo médio dessas entregas num dia. Os pedidos que não
puderem ser transportados num dia, são descartados e retornam ao fornecedor.

Entre outros dados de entrada que se possam considerar, deve-se incluir:
- conjunto de pedidos expresso, ***P***, com volume ***Vp***, peso ***Wp*** e tempo estimado de entrega ***Tp***