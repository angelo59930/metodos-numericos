
    FILE *fd;
    fd = fopen("matrizIndep.dat","r");
    if ( fd == NULL )
    {
        puts ( "No se puede abrir el archivo");
    }

    //Cargo los datos leidos en el array
	for(int i = 0; i < filas; i++) {
		do {
        fscanf(fd, "%lf", &(b[i]));
			} while((c = fgetc(fd)) != '\n');
	}

    //imprimo la matriz para verificar que lo leyo correctamente
      
	printf("LOS TERMINOS INDEPENDIENTES DE LA MATRIZ SON:\n");
    	
    for(int i=0;i<filas;i++){
	        printf("%lf ",b[i]);
   		printf("\n");        
	}

	
	//ejemplo de como escribir en archivo
	/*
	    FILE * file;
        file= fopen("matriz_1.dat", "w");
		
      for(i=0;i<3;i++){
            fprintf(file, "%lf	%lf	%lf	%lf\n", m[i][0],m[i][1],m[i][2],m[i][3]);
        }
        
      */  
	

        
 

