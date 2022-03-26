# BEE 1523 - Estacionamento Linear

A ideia para resolver esse exercício é criar uma std::stack que irá guardar os horários de saída dos veículos para sabermos se é possível que todos os motoristas façam uso do estacionamento.
A medida que a entrda é lida, linha a linha, é necessário:
- atualizar o "horário atual" com base no horário informado na entrada (lembrando que os horários estão em ordem crescente) simulado a chegada dos carros nos estacionamento
- atualizar o estacionamento: se o horário atual for maior que o horário de saída do topo da pilha, retirar esse valor e compará-lo com o segundo valor da stack, se o horário de saída do segundo for maior, repetir o processo, se não, atualizar o valor "possivel" para 0, pois o segundo veículo deveria sair primeiro, mas não pode pois o está bloqueado. Esse processo ocorre até o horário de saída do topo da stack seja maior que o horário atual

No fim das entradas, será necessário ainda verificar os veículos que sobraram. Se depois desse processo a varíavel possivel continuar 1, signfica que é possível que todos os motoristas façam uso do estacionamento