CC = cc
CFLAGS = -Wall -Wextra -Werror
UTILS = ./ultims/ultims.a
RM = rm -rf

SERVER = server
CLIENT = client
SERVER_BONUS = server_bonus
CLIENT_BONUS = client_bonus

SV = server.c
SV_OBJ = $(SV:.c=.o)

CL = client.c
CL_OBJ = $(CL:.c=.o)

SV_BONUS = server_bonus.c
SV_BONUS_OBJ = $(SV_BONUS:.c=.o)

CL_BONUS = client_bonus.c
CL_BONUS_OBJ = $(CL_BONUS:.c=.o)

all: $(SERVER) $(CLIENT)

bonus : $(SERVER_BONUS) $(CLIENT_BONUS)

$(UTILS):
		$(MAKE) -C ./ultims
$(SERVER): $(SV_OBJ) $(UTILS)
		$(CC) $(CFLAGS) $(SV_OBJ) $(UTILS) -o server
$(CLIENT): $(CL_OBJ) $(UTILS)
		$(CC) $(CFLAGS) $(CL_OBJ) $(UTILS) -o client
$(SERVER_BONUS): $(SV_BONUS_OBJ) $(UTILS)
		$(CC) $(CFLAGS) $(SV_BONUS_OBJ) $(UTILS) -o server_bonus
$(CLIENT_BONUS): $(CL_BONUS_OBJ) $(UTILS)
		$(CC) $(CFLAGS) $(CL_BONUS_OBJ) $(UTILS) -o client_bonus

%.o:%.c minitalk.h server.c client.c minitalk_bonus.h server_bonus.c client_bonus.c
		$(CC) $(CFLAGS) -c $< -o $@

clean:
		$(MAKE) -C ./ultims clean
		$(RM) $(SV_OBJ) $(CL_OBJ)
		$(RM) $(SV_BONUS_OBJ) $(CL_BONUS_OBJ)

fclean: clean
		$(MAKE) -C ./ultims fclean
		$(RM) $(SERVER) $(CLIENT)
		$(RM) $(CLIENT_BONUS) $(SERVER_BONUS)

re: fclean all

