


int motor_init(unsigned int *p_led){
	printf("Liga motor\n");
	*(p_led) = 0b1101;
}
int motor_halt(unsigned int *p_led){
	printf("Freia motor\n");
	*(p_led) = 0x00;
}
int motor_en(unsigned int *p_led){
	printf("Habilita motor\n");
	*(p_led) = 0b1101;
}
int motor_dir(unsigned int *p_led){
	printf("Inverte Direcao\n");
	*(p_led) = 0b1111;
}
int motor_vel(unsigned int *p_led){
	printf("Acelerando\n");
	*(p_led) =  0b0001;
	usleep(3000000);
	printf("Velocidade media\n");
	*(p_led) = 0b1001;
    usleep(3000000);
	printf("VELECIDADE MAXIMA!\n");
	*(p_led) = 0b1101;
    usleep(3000000);

}
