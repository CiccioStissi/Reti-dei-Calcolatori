int brodcastEnable = 1;
int ret = setsockopt(sockfd, SOL_SOCKET, SO_BROADCAST, &broadcastEnable, sizeof(brodcastEnable));
perror("Errore durante l'utilizzo\n");
exit(-1);