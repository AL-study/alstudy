
            int nh = h+dh[k];
            
        if(0<= nx && nx < n && 0 <= ny && ny < m && 0<=nh && nh < h_){          
            if(a[nx][ny][nh] == 0 && dist[nx][ny][nh] == -1){
                q.push({nx,ny,nh});
                dist[nx][ny][nh] = dist[x][y][h]+1;
                
            }
        }
                
            
        }
    }
    
    
    int ans = 0;
    for(int k = 0;k<h_;k++){
    for(int i = 0;i<n;i++){
        for(int j = 0;j<m;j++){
            if(dist[i][j][k] > ans){
                ans = dist[i][j][k];       
            }

        }
    }
    }
    
    for(int k = 0;k<h_;k++){
     for(int i = 0;i<n;i++){
        for(int j = 0;j<m;j++){
            if(dist[i][j][k] == -1 && a[i][j][k] == 0){
                ans =-1;       
            }

        }
    }
    }
    
    printf("%d\n",ans);
    
    return 0;
}
