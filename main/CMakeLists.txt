idf_component_register(SRCS "main.cpp"
                        INCLUDE_DIRS "."
                        REQUIRES utils
                        PRIV_REQUIRES esp_timer)
