# Reference:
https://www.alexedwards.net/blog/serverless-api-with-go-and-aws-lambda

* Create main executable from main.go
# env GOOS=linux GOARCH=amd64 go build -o main hello_world.go

* Create main.zip from main executable
# zip -j main.zip main

* Create function
# aws lambda create-function --function-name helloWorldsdk --runtime go1.x --role arn:aws:iam::361108732765:role/service-role/DCP_SDK_AuditOpsRole --handler main --zip-file fileb://./main.zip
Note: --role has to be created depending on what access is required by lambda function.
Eg.  arn:aws:iam::361108732765:role/lambda_basic_execution can be used for lambd execution with no access to aws resources.

* Invoke function
# aws lambda invoke --function-name helloWorldsdk out.json --log-type Tail

* Look for output
# cat out.json
