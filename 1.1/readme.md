# Deploy TimePrinter to Kubernetes




```bash
#create a k3d cluster
k3d cluster create -a 2

#test image
docker run cassielu123/printtime-app:latest

# Create the deployment
kubectl create deployment timeprinter-dep --image=cassielu123/printtime-app:latest

# Check pods
kubectl get pods
#Check deployments
kubectl get deployments

# View logs
kubectl logs -f deployment/timeprinter-dep
