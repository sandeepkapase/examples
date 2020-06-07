package config

// Configurations exported
type Configurations struct {
	Server            ServerConfigurations
	Database          DatabaseConfigurations
	EXAMPLE_PATH      string
	EXAMPLE_VAR       string
	EXAMPLE_VAR_UNSET string
}

// ServerConfigurations exported
type ServerConfigurations struct {
	Port int
}

// DatabaseConfigurations exported
type DatabaseConfigurations struct {
	DBName     string
	DBUser     string
	DBPassword string
}
