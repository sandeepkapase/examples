package main

import (
	"fmt"

	c "./config"
	"github.com/spf13/viper"
)

/* We need to initialize viper parameter like config path, config
   file, file extension, read env.
   Once done we can use viper.Unmarshal to read onto predefined
   structure or also can use viper.GetString, viper.GetInt to read
   configurations.
   Note that enviroment variable will take precedence over config file parameters.
   If config is not found either in config file or env then it will
   get default value if set else will be empty.
   Also, in viper configuration, keys are case
   insensitive. i.e. DB_NAME and db_name have no difference.
*/
func main() {
	// Set the file name of the configurations file
	viper.SetConfigName("config")

	// Set the path to look for the configurations file
	viper.AddConfigPath(".")

	// Enable VIPER to read Environment Variables
	viper.AutomaticEnv()

	viper.SetConfigType("yml")
	var configuration c.Configurations

	if err := viper.ReadInConfig(); err != nil {
		fmt.Printf("Error reading config file, %s", err)
	}

	// Set undefined variables
	viper.SetDefault("database.dbname", "test_db")
	viper.SetDefault("EXAMPLE_VAR_UNSET", "unset_default")

	err := viper.Unmarshal(&configuration)
	if err != nil {
		fmt.Printf("Unable to decode into struct, %v", err)
	}

	// Reading variables using the model
	fmt.Println("Reading variables using the model..")
	fmt.Println("Database is\t", configuration.Database.DBName)
	fmt.Println("Port is\t\t", configuration.Server.Port)
	fmt.Println("EXAMPLE_PATH is\t", configuration.EXAMPLE_PATH)
	fmt.Println("EXAMPLE_VAR is\t", configuration.EXAMPLE_VAR)
	fmt.Println("EXAMPLE_VAR_UNSET is\t", configuration.EXAMPLE_VAR_UNSET)

	// Reading variables without using the model
	fmt.Println("\nReading variables without using the model..")
	fmt.Println("Database is\t", viper.GetString("database.dbname"))
	fmt.Println("Port is\t\t", viper.GetInt("server.port"))
	fmt.Println("EXAMPLE_PATH is\t", viper.GetString("EXAMPLE_PATH"))
	fmt.Println("EXAMPLE_VAR is\t", viper.GetString("EXAMPLE_VAR"))
	fmt.Println("EXAMPLE_VAR_UNSET is\t", viper.GetString("EXAMPLE_VAR_UNSET"))
	fmt.Printf("Viper:%+v", viper.AllSettings())

}
