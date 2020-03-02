# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    init.sh                                            :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: mwane <mwane@student.42.fr>                +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2020/03/02 16:55:21 by mwane             #+#    #+#              #
#    Updated: 2020/03/02 16:59:51 by mwane            ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

cd containers/Nginx
docker build . -t test_nginx
cd ../..
eval $(minikube docker-env)
cd deployment
kubectl apply -f nginx.yaml