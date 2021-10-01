
    FILE *fp;
    char ch;
    fp = fopen("matriz.dat","r");
    if ( fp == NULL )
    {
        puts ( "No se puede abrir el archivo");
    }

    //contador de filas
    int filas=0;
    char c;
    int maxValues = 0;
	int columnas;
    
    while((c = fgetc(fp)) != EOF)
    {
        if(c == '\n'){
            filas++;
		}
    }

    printf("numero de filas=%i\n",filas);

    //cerramos y reabrimos el archivo para resetear el puntero
    fclose(fp);
    fp = fopen("matriz.dat","r");
    double m[filas][1000];


    //Cargo los datos leidos en el array
    int i, j;
	for(i = 0; i < filas; i++) {
		j = 0;
		do {
        fscanf(fp, "%lf", &(m[i][j]));
        j++;
			} while((c = fgetc(fp)) != '\n');
	}

	columnas = j;
	
	printf("numero de columnas=%i\n\n",columnas);

    //imprimo la matriz para verificar que lo leyo correctamente
      
	printf("LOS ELEMENTOS DE LA MATRIZ SON:\n");
    	
    for(i=0;i<filas;i++){
	    for(j=0;j<columnas;j++){
	        printf("%lf ",m[i][j]);
	    }
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
	

        
 

